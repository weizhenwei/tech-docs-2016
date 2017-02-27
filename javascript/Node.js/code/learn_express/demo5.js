
var express = require("express");
var bodyParser = require("body-parser");
var app = express();

var urlencodedParser = bodyParser.urlencoded({extended: false});

app.use(express.static("public"));

app.get("/index.html", function(req, res) {
    console.log("request index.html page");
    res.sendFile(__dirname + "/" + "index5.html");
});

app.post("/process_post", urlencodedParser, function(req, res) {
    console.log("request process get");

    // json format;
    // var response = {
    //     first_name:req.query.first_name,
    //     last_name:req.query.last_name
    // };
    var response = "first_name: " + req.body.first_name + ", last_name: " + req.body.last_name;
    console.log("send response: " + response);
    res.end(response);
    // res.end(JSON.stringfy(response));
    // res.end(JSON.toStr(response));
});

var server = app.listen(8081, function() {
    var host = server.address().address;
    var port = server.address().port;

    console.log("access: http://%s:%s", host, port);
});

