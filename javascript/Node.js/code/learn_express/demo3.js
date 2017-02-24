
var express = require("express");
var app = express();

app.use(express.static("public"));

app.get("/", function(req, res) {
    console.log("request main page");
    res.send("Hello, Express");
});

var server = app.listen(8081, function() {
    var host = server.address().address;
    var port = server.address().port;

    console.log("access: http://%s:%s", host, port);
});

