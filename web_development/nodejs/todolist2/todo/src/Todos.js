import React from 'react'
import { useState, useEffect } from 'react'
import { useParams } from 'react-router-dom'
import './todos.css'

function Todos() {
    const [todo, setTodo] = useState([])
    const [input, setInput] = useState("")
    let params = useParams();

    const handleChange = event => {
        setInput(event.target.value);
    }

    useEffect(() => {
        fetch(`http://localhost:8080/todos/${params.id}`)
            .then((res) => res.json())
            .then(setTodo)
    }, []);

    function addTask() {
        const newTask = {
            task: input,
        }
        fetch(`http://localhost:8080/addtodo/${params.id}`, {
            method: "POST",
            body: JSON.stringify(newTask),
            headers: {
                "Content-Type": "application/json; charset=UTF-8",
            },
        })
            .then((resp) => resp.json())
            .then(setTodo);
    }

    return (
        <div className='todos'>
            <h1>To Do List</h1>
            {todo.map((todo) => {
                return (
                    <> 
                        <li key={todo.id}>
                            <input type="checkbox" checked={todo.complated} onChange={() => {
                                const isCompleted = {
                                    id: todo.id
                                }
                                fetch(`http://localhost:8080/isCompleted/${params.id}`, {
                                    method: "POST",
                                    body: JSON.stringify(isCompleted),
                                    headers: {
                                        "Content-Type": "application/json; charset=UTF-8",
                                    },
                                })
                                    .then((resp) => resp.json())
                                    .then(setTodo);
                            }} />
                            <span>{todo.task}</span>
                        </li>
                    </>
                )
            }
            )}
            <input type="text" placeholder='Type a task' onChange={handleChange} value={input} />
            <div className='buttons'>
                <button onClick={addTask}>Add task</button>
                <button onClick={() => {
                    fetch(`http://localhost:8080/deleteTodo/${params.id}`, {
                        method: "DELETE",
                        headers: {
                            "Content-Type": "application/json; charset=UTF-8",
                        },
                    })
                        .then((resp) => resp.json())
                        .then(setTodo);
                }}>Delete task</button>
            </div>
        </div>
    )
}

export default Todos