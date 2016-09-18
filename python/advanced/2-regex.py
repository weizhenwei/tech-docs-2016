#!/usr/bin/env python
# -*- coding: UTF-8 -*-

import re

# match, just match at the beginning
print(re.match("www", "www.baidu.com").span())
print(re.match("baidu", "www.baidu.com"))

# search, search all the string
print(re.search("www", "www.baidu.com").span())
print(re.search("baidu", "www.baidu.com").span())
print(re.search("baiduu", "www.baidu.com"))

