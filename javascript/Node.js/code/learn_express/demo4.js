
var express = require("express");
var app = express();

app.use(express.static("public"));

app.get("/", function(req, res) {
    console.log("request index.htm page");
    res.sendFile(__dirname + "/" + "index4.html");
});

app.get("/process_get", function(req, res) {
    console.log("request process get");

    // json format;
    var response = {
        first_name:req.query.first_name,
        last_name:req.query.last_name
    };
    // var response = "first_name: " + req.query.first_name + ", last_name: " + req.query.last_name;
    console.log("send response: " + response);
    res.end(JSON.stringify(response));
});

var server = app.listen(8081, function() {
    var host = server.address().address;
    var port = server.address().port;

    console.log("access: http://%s:%s", host, port);
});

