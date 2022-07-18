const express = require("express")
const path = require("path")
const cors = require("cors")
const fs = require("fs");
const tasks = require('./tasks.json');
const { send } = require("process");

const server = express();
server.use(cors());
server.use(express.json());

server.get("/", (req, res) => {
    fs.promises.readFile(path.resolve("users.json"), "utf8")
        .then((todos) => {
            res.send(JSON.parse(todos));
        })

})

server.get("/todos/:id", (req, res) => {
    fs.promises.readFile(path.resolve("tasks.json"), "utf8")
        .then((todos) => {
            todos = JSON.parse(todos);
            res.json(todos.filter((ev) => ev.userId == req.params.id))
        })
})

server.post("/addtodo/:id", (req, res) => {
    fs.promises.readFile(path.resolve("tasks.json"), "utf8")
    .then((todos) => {
        todos = JSON.parse(todos)
        todos.push({
            id: (todos.length + 1) * 10,
            task: req.body.task,
            userId: req.params.id,
            complated: false
        })
        console.log(todos)
        fs.promises.writeFile(path.resolve("tasks.json"), JSON.stringify(todos, undefined, 2))
        return (res.json(todos.filter((ev) => ev.userId == req.params.id)))
    })
})

server.post("/isCompleted/:id", (req, res) => {
    fs.promises.readFile(path.resolve("tasks.json"), "utf8")
    .then((todos) => {
        todos = JSON.parse(todos)
        todos.forEach((el) => {
            if (el.id == req.body.id) {
                el.complated = !el.complated;
            }
        });
        fs.promises.writeFile(path.resolve("tasks.json"), JSON.stringify(todos, undefined, 2))
        return (res.json(todos.filter((ev) => ev.userId == req.params.id)))
    })
})

server.delete("/deleteTodo/:id", (req, res) => {
    fs.promises.readFile(path.resolve("tasks.json"), "utf8")
        .then((todos) => {
            todos = JSON.parse(todos)
            const newTodos = todos.filter((ev) => ev.userId == req.params.id && !ev.complated)
            fs.promises.writeFile(path.resolve("tasks.json"), JSON.stringify(newTodos, undefined, 2))
            return (res.json(newTodos))
        })
})

server.listen(8080);