const express = require("express")
const path = require("path")
const cors = require("cors")
const fs = require("fs");
const tasks = require('./tasks.json');
const { send } = require("process");

const server = express();
server.use(cors());
server.use(express.json());

const mongoose = require("mongoose");
const { Db } = require("mongodb");
const url = "mongodb://localhost:27017/toDo"

mongoose.connect(url).then((ans) => {
    console.log("Connected Successful")
}).catch((err) => {
    console.log("Error in the Connection")
})
const Schema = mongoose.Schema

const users_structure = new Schema({
    id: Number,
    username: String
})

const todos_structure = new Schema({
    id: Number,
    task: String,
    userId: Number,
    complated: Boolean,
})

const users = mongoose.model(
    "users", users_structure)

const todos = mongoose.model(
    "todos", todos_structure)

users.find().then(ans => {
    console.log(typeof (ans[0].id))
    console.log(ans[0].username)
})

server.get("/", async (req, res) => {
    const usersList = await users.find().then(ans => {
        return ans;
    });
    res.send(usersList);

})

server.get("/todos/:id", async (req, res) => {

    const toDoList = await todos.find().then((toDo) => {
        return toDo;
    })

    res.send(toDoList.filter((ev) => ev.userId == req.params.id))
})

server.post("/addtodo/:id", async (req, res) => {
    const newTodo = {
        id: Date.now(),
        task: req.body.task,
        userId: req.params.id,
        complated: false
    };

    await todos.insertMany(newTodo)
    const toDoList = await todos.find().then((toDo) => {
        return toDo;
    })
    res.send(toDoList.filter((ev) => ev.userId == req.params.id))
})

server.post("/isCompleted/:id", async (req, res) => {
    let toDoList = await todos.find().then((toDo) => {
        return (toDo.filter((el) => el.id == req.body.id))
    })
    const filter = { id: req.body.id };
    const update = { complated: !(toDoList[0].complated) };
    const updatedTodo = await todos.findOneAndUpdate(filter, update);

    const newToDoList = await todos.find().then((toDo) => {
        return toDo;
    })
    res.send(newToDoList.filter((ev) => ev.userId == req.params.id))

})

server.delete("/deleteTodo/:id", async (req, res) => {
    const deletedTask = await todos.deleteMany({userId: req.params.id});
    res.send(deletedTask);
})

server.listen(8080);
