import React, { useState, useEffect } from "react";
import { Link } from 'react-router-dom';
import './users.css'



function Users() {
    const[users, setUsers] = useState([])

    useEffect(() => {
        fetch("http://localhost:8080/")
        .then((resp) => resp.json())
        .then((resp) => { setUsers(resp)}
        )
      }, [])

    return(
        <div className="userslist">
        <h1>Users List</h1>
        <ol>
        {users.map((user) => {
            return (
                <li id="li" key={user.id}>
                    <Link id="user" to={`/users/${user.id}`}>{user.username}</Link>
                </li>
            )
        })} 
        </ol>
        </div>
    )
}

export default Users;