
var express = require("express");
var app = express();

app.get("/", function(req, res) {
    console.log("request get page");
    res.send("Hello, Get");
});

app.post("/", function(req, res) {
    console.log("request post page");
    res.send("Hello, Post");
});

app.get("/del_user", function(req, res) {
    console.log("request del_user page");
    res.send("Hello, del_user");
});

app.get("/list_user", function(req, res) {
    console.log("request list_user page");
    res.send("Hello, list_user");
});

app.get("/ab*cd", function(req, res) {
    console.log("request ab*cd page");
    res.send("Hello, ab*ce/regex");
});

var server = app.listen(8081, function() {
    var host = server.address().address;
    var port = server.address().port;

    console.log("access: http://%s:%s", host, port);
});

