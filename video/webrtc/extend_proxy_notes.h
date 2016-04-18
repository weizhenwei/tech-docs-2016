namespace webrtc {

// Proxy class call function through the Synchronous way;


// return function call value by calling Invoke() function;
// typename R is the return type;
// typename C is class name;
// typename M is class C's member function;
// parameters of function M can be 0~5;
template <typename R>
class ReturnType {
 public:
  template<typename C, typename M>
  void Invoke(C* c, M m) { r_ = (c->*m)(); }
  template<typename C, typename M, typename T1>
  void Invoke(C* c, M m, T1 a1) { r_ = (c->*m)(a1); }
  template<typename C, typename M, typename T1, typename T2>
  void Invoke(C* c, M m, T1 a1, T2 a2) { r_ = (c->*m)(a1, a2); }
  template<typename C, typename M, typename T1, typename T2, typename T3>
  void Invoke(C* c, M m, T1 a1, T2 a2, T3 a3) { r_ = (c->*m)(a1, a2, a3); }
  template<typename C, typename M, typename T1, typename T2, typename T3,
      typename T4>
  void Invoke(C* c, M m, T1 a1, T2 a2, T3 a3, T4 a4) {
    r_ = (c->*m)(a1, a2, a3, a4);
  }
  template<typename C, typename M, typename T1, typename T2, typename T3,
     typename T4, typename T5>
  void Invoke(C* c, M m, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5) {
    r_ = (c->*m)(a1, a2, a3, a4, a5);
  }

  R value() { return r_; }

 private:
  R r_;  // return value stored here;
};


// specific ReturnType class with return void value;
template <>
class ReturnType<void> {
 public:
  template<typename C, typename M>
  void Invoke(C* c, M m) { (c->*m)(); }
  template<typename C, typename M, typename T1>
  void Invoke(C* c, M m, T1 a1) { (c->*m)(a1); }
  template<typename C, typename M, typename T1, typename T2>
  void Invoke(C* c, M m, T1 a1, T2 a2) { (c->*m)(a1, a2); }
  template<typename C, typename M, typename T1, typename T2, typename T3>
  void Invoke(C* c, M m, T1 a1, T2 a2, T3 a3) { (c->*m)(a1, a2, a3); }

  void value() {}
};

namespace internal {

// synchronous method call, which can handle message;
class SynchronousMethodCall
    : public rtc::MessageData,
      public rtc::MessageHandler {
 public:
  explicit SynchronousMethodCall(rtc::MessageHandler* proxy)
      : e_(), proxy_(proxy) {}
  ~SynchronousMethodCall() {}

  // if called in same thread, handle message directly.
  // else, post event to target thread and wait target thread to finish message
  // handling; Tha't why called Synchronous.
  void Invoke(rtc::Thread* t) {
    if (t->IsCurrent()) {
      proxy_->OnMessage(NULL);    // handle message;
    } else {
      e_.reset(new rtc::Event(false, false));
      t->Post(this, 0);
      e_->Wait(rtc::Event::kForever);
    }
  }

 private:
  void OnMessage(rtc::Message*) { proxy_->OnMessage(NULL); e_->Set(); }
  rtc::scoped_ptr<rtc::Event> e_;
  rtc::MessageHandler* proxy_;
};

}

// Wrapper of method call with 0 parameter;
template <typename C, typename R>
class MethodCall0 : public rtc::Message,
                    public rtc::MessageHandler {
 public:
  typedef R (C::*Method)();
  // Initialized with Class C and its member function m;
  MethodCall0(C* c, Method m) : c_(c), m_(m) {}

  // call the function in synchronous way,
  // that's, call function directly in same thread,
  // or post event to different thread and wait target thread to finish call
  // and return;
  R Marshal(rtc::Thread* t) {
    internal::SynchronousMethodCall(this).Invoke(t);
    return r_.value();
  }

 private:
  void OnMessage(rtc::Message*) { r_.Invoke(c_, m_); }

  C* c_;
  Method m_;
  ReturnType<R> r_;
};

// const version of MethodCall0;
template <typename C, typename R>
class ConstMethodCall0 : public rtc::Message,
                         public rtc::MessageHandler {
 public:
  typedef R (C::*Method)() const;
  ConstMethodCall0(C* c, Method m) : c_(c), m_(m) {}

  R Marshal(rtc::Thread* t) {
    internal::SynchronousMethodCall(this).Invoke(t);
    return r_.value();
  }

 private:
  void OnMessage(rtc::Message*) { r_.Invoke(c_, m_); }

  C* c_;
  Method m_;
  ReturnType<R> r_;
};


// Method call with 1 parameter;
template <typename C, typename R, typename T1>
class MethodCall1 : public rtc::Message,
                    public rtc::MessageHandler {
 public:
  typedef R (C::*Method)(T1 a1);
  MethodCall1(C* c, Method m, T1 a1) : c_(c), m_(m), a1_(a1) {}

  R Marshal(rtc::Thread* t) {
    internal::SynchronousMethodCall(this).Invoke(t);
    return r_.value();
  }

 private:
  void OnMessage(rtc::Message*) { r_.Invoke(c_, m_, a1_); }

  C* c_;
  Method m_;
  ReturnType<R> r_;
  T1 a1_;
};

template <typename C, typename R, typename T1>
class ConstMethodCall1 : public rtc::Message,
                         public rtc::MessageHandler {
 public:
  typedef R (C::*Method)(T1 a1) const;
  ConstMethodCall1(C* c, Method m, T1 a1) : c_(c), m_(m), a1_(a1) {}

  R Marshal(rtc::Thread* t) {
    internal::SynchronousMethodCall(this).Invoke(t);
    return r_.value();
  }

 private:
  void OnMessage(rtc::Message*) { r_.Invoke(c_, m_, a1_); }

  C* c_;
  Method m_;
  ReturnType<R> r_;
  T1 a1_;
};

template <typename C, typename R, typename T1, typename T2>
class MethodCall2 : public rtc::Message,
                    public rtc::MessageHandler {
 public:
  typedef R (C::*Method)(T1 a1, T2 a2);
  MethodCall2(C* c, Method m, T1 a1, T2 a2) : c_(c), m_(m), a1_(a1), a2_(a2) {}

  R Marshal(rtc::Thread* t) {
    internal::SynchronousMethodCall(this).Invoke(t);
    return r_.value();
  }

 private:
  void OnMessage(rtc::Message*) { r_.Invoke(c_, m_, a1_, a2_); }

  C* c_;
  Method m_;
  ReturnType<R> r_;
  T1 a1_;
  T2 a2_;
};

template <typename C, typename R, typename T1, typename T2, typename T3>
class MethodCall3 : public rtc::Message,
                    public rtc::MessageHandler {
 public:
  typedef R (C::*Method)(T1 a1, T2 a2, T3 a3);
  MethodCall3(C* c, Method m, T1 a1, T2 a2, T3 a3)
      : c_(c), m_(m), a1_(a1), a2_(a2), a3_(a3) {}

  R Marshal(rtc::Thread* t) {
    internal::SynchronousMethodCall(this).Invoke(t);
    return r_.value();
  }

 private:
  void OnMessage(rtc::Message*) { r_.Invoke(c_, m_, a1_, a2_, a3_); }

  C* c_;
  Method m_;
  ReturnType<R> r_;
  T1 a1_;
  T2 a2_;
  T3 a3_;
};

template <typename C, typename R, typename T1, typename T2, typename T3,
    typename T4>
class MethodCall4 : public rtc::Message,
                    public rtc::MessageHandler {
 public:
  typedef R (C::*Method)(T1 a1, T2 a2, T3 a3, T4 a4);
  MethodCall4(C* c, Method m, T1 a1, T2 a2, T3 a3, T4 a4)
      : c_(c), m_(m), a1_(a1), a2_(a2), a3_(a3), a4_(a4) {}

  R Marshal(rtc::Thread* t) {
    internal::SynchronousMethodCall(this).Invoke(t);
    return r_.value();
  }

 private:
  void OnMessage(rtc::Message*) { r_.Invoke(c_, m_, a1_, a2_, a3_, a4_); }

  C* c_;
  Method m_;
  ReturnType<R> r_;
  T1 a1_;
  T2 a2_;
  T3 a3_;
  T4 a4_;
};

template <typename C, typename R, typename T1, typename T2, typename T3,
    typename T4, typename T5>
class MethodCall5 : public rtc::Message,
                    public rtc::MessageHandler {
 public:
  typedef R (C::*Method)(T1 a1, T2 a2, T3 a3, T4 a4, T5 a5);
  MethodCall5(C* c, Method m, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5)
      : c_(c), m_(m), a1_(a1), a2_(a2), a3_(a3), a4_(a4), a5_(a5) {}

  R Marshal(rtc::Thread* t) {
    internal::SynchronousMethodCall(this).Invoke(t);
    return r_.value();
  }

 private:
  void OnMessage(rtc::Message*) { r_.Invoke(c_, m_, a1_, a2_, a3_, a4_, a5_); }

  C* c_;
  Method m_;
  ReturnType<R> r_;
  T1 a1_;
  T2 a2_;
  T3 a3_;
  T4 a4_;
  T5 a5_;
};

}  // namespace webrtc;


// defined at peerconnectionfactory.h
class PeerConnectionFactory {

};

// proxy macro extension;
class PeerConnectionFactoryProxy : public PeerConnectionFactoryInterface {
protected:
    typedef PeerConnectionFactoryInterface C;
    PeerConnectionFactoryProxy(rtc::Thread* thread, C* PeerConnectionFactory) : owner_thread_(thread), c_(PeerConnectionFactory) {}
    ~PeerConnectionFactoryProxy() {
        // Call PeerConnectionFactoryProxy::Release_s() to destructor the object;
        MethodCall0<PeerConnectionFactoryProxy, void> call(this, &PeerConnectionFactoryProxy::Release_s);
        call.Marshal(owner_thread_);
    }
public:
    static rtc::scoped_refptr<C> Create(rtc::Thread* thread, C* PeerConnectionFactory) {
        return new rtc::RefCountedObject<PeerConnectionFactoryProxy>(thread, PeerConnectionFactory);
    }
    
    void SetOptions(const Options& a1) override {
        MethodCall1<C, void, const Options&> call(c_.get(), &C::SetOptions, a1);
        return call.Marshal(owner_thread_);
    }

    rtc::scoped_refptr<PeerConnectionInterface> CreatePeerConnection(
            const PeerConnectionInterface::RTCConfiguration& a1,
            const MediaConstraintsInterface* a2,
            rtc::scoped_ptr<cricket::PortAllocator> a3,
            rtc::scoped_ptr<DtlsIdentityStoreInterface> a4,
            PeerConnectionObserver* a5) override {
        return owner_thread_->Invoke<rtc::scoped_refptr<PeerConnectionInterface>>(
                rtc::Bind(&PeerConnectionFactoryProxy::CreatePeerConnection_ot,
                              this, a1, a2, a3.release(), a4.release(), a5));
    }

  rtc::scoped_refptr<PeerConnectionInterface> CreatePeerConnection(
          const PeerConnectionInterface::RTCConfiguration& a1,
          rtc::scoped_ptr<cricket::PortAllocator> a3,
          rtc::scoped_ptr<DtlsIdentityStoreInterface> a4,
          PeerConnectionObserver* a5) override {
      return owner_thread_->Invoke<rtc::scoped_refptr<PeerConnectionInterface>>(
              rtc::Bind(&PeerConnectionFactoryProxy::CreatePeerConnection_ot,
                  this, a1, a3.release(), a4.release(), a5));
  }

rtc::scoped_refptr<MediaStreamInterface> CreateLocalMediaStream(const std::string& a1) override {
    MethodCall1<C, rtc::scoped_refptr<MediaStreamInterface>, const std::string&> call(c_.get(), &C::CreateLocalMediaStream, a1);
    return call.Marshal(owner_thread_);
}

rtc::scoped_refptr<AudioSourceInterface> CreateAudioSource(const MediaConstraintsInterface* a1) override {
    MethodCall1<C, rtc::scoped_refptr<AudioSourceInterface>, const MediaConstraintsInterface*> call(c_.get(), &C::CreateAudioSource, a1);
    return call.Marshal(owner_thread_);
}

rtc::scoped_refptr<AudioSourceInterface> CreateAudioSource(const cricket::AudioOptions& a1) override {
    MethodCall1<C, rtc::scoped_refptr<AudioSourceInterface>, const cricket::AudioOptions&> call(c_.get(), &C::CreateAudioSource, a1);
    return call.Marshal(owner_thread_);
}

rtc::scoped_refptr<VideoTrackSourceInterface> CreateVideoSource(cricket::VideoCapturer* a1, const MediaConstraintsInterface* a2) override {
    MethodCall2<C, rtc::scoped_refptr<VideoTrackSourceInterface>, cricket::VideoCapturer*, const MediaConstraintsInterface*> call(c_.get(), &C::CreateVideoSource, a1, a2);
    return call.Marshal(owner_thread_);
}

rtc::scoped_refptr<VideoTrackSourceInterface> CreateVideoSource(cricket::VideoCapturer* a1) override {
    MethodCall1<C, rtc::scoped_refptr<VideoTrackSourceInterface>, cricket::VideoCapturer*> call(c_.get(), &C::CreateVideoSource, a1);
    return call.Marshal(owner_thread_);
}

rtc::scoped_refptr<VideoTrackInterface> CreateVideoTrack(const std::string& a1, VideoTrackSourceInterface* a2) override {
    MethodCall2<C, rtc::scoped_refptr<VideoTrackInterface>, const std::string&, VideoTrackSourceInterface*> call(c_.get(), &C::CreateVideoTrack, a1, a2);
    return call.Marshal(owner_thread_);
}

rtc::scoped_refptr<AudioTrackInterface> CreateAudioTrack(const std::string& a1, AudioSourceInterface* a2) override {
    MethodCall2<C, rtc::scoped_refptr<AudioTrackInterface>, const std::string&, AudioSourceInterface*> call(c_.get(), &C::CreateAudioTrack, a1, a2);
    return call.Marshal(owner_thread_);
}

bool StartAecDump(rtc::PlatformFile a1, int64_t a2) override {
    MethodCall2<C, bool, rtc::PlatformFile, int64_t> call(c_.get(), &C::StartAecDump, a1, a2);
    return call.Marshal(owner_thread_);
}

void StopAecDump() override {
    MethodCall0<C, void> call(c_.get(), &C::StopAecDump);
    return call.Marshal(owner_thread_);
}

bool StartRtcEventLog(rtc::PlatformFile a1) override {
    MethodCall1<C, bool, rtc::PlatformFile> call(c_.get(), &C::StartRtcEventLog, a1);
    return call.Marshal(owner_thread_);
}

void StopRtcEventLog() override {
    MethodCall0<C, void> call(c_.get(), &C::StopRtcEventLog);
    return call.Marshal(owner_thread_);
}

private:
rtc::scoped_refptr<PeerConnectionInterface> CreatePeerConnection_ot(
        const PeerConnectionInterface::RTCConfiguration& a1,
        const MediaConstraintsInterface* a2, cricket::PortAllocator* a3,
        DtlsIdentityStoreInterface* a4, PeerConnectionObserver* a5) {
    rtc::scoped_ptr<cricket::PortAllocator> ptr_a3(a3);
    rtc::scoped_ptr<DtlsIdentityStoreInterface> ptr_a4(a4);
    return c_->CreatePeerConnection(a1, a2, std::move(ptr_a3), std::move(ptr_a4), a5);
}

rtc::scoped_refptr<PeerConnectionInterface> CreatePeerConnection_ot(
        const PeerConnectionInterface::RTCConfiguration& a1, cricket::PortAllocator* a3,
        DtlsIdentityStoreInterface* a4, PeerConnectionObserver* a5) {
    rtc::scoped_ptr<cricket::PortAllocator> ptr_a3(a3);
    rtc::scoped_ptr<DtlsIdentityStoreInterface> ptr_a4(a4);
    return c_->CreatePeerConnection(a1, std::move(ptr_a3), std::move(ptr_a4), a5);
}

private:
  void Release_s() { c_ = NULL; }
  mutable rtc::Thread* owner_thread_;
  rtc::scoped_refptr<C> c_;
};  // PeerConnectionFactoryProxy 


int main(void) {
    return 0;
}

