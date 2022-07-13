import express from 'express'
import path from 'path'

const app = express();

app.get('/', (req, res) => {
    res.sendFile(path.resolve("public/index.html"));
});

app.get('/welcome', (req, res) => {
    res.send("Welcome to our web page!");
});

app.listen(8000)