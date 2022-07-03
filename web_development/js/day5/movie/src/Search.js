import { useState } from "react";
import Movies from "./Movie";
import { listOfMovies } from "./Movie";
import img1 from './1+1.jpg'
import img2 from './spy.jpg'
import img3 from './wonder.jpg'

const additional = [{id: Date.now(), name: "The Intouchables", image:img1, description: "Biography, Comedy, Drama"},
                    {id: Date.now(), name: "Spy", image:img2, description: "Comedy, Action"},
                    {id: Date.now(), name: "Wonder", image:img3, description: "Family, Drama"}]

function Search() {
    const[input, setInput] = useState("");
    const[item, setItem] = useState({listOfMovies});
    function add() {     
        setItem(listOfMovies.push(additional[Math.floor(Math.random() * additional.length)]))
    }

    return (
        <div className="search">
            <div id  = "buttonBlock">
                <div id = "count">Count: {listOfMovies.length}</div> 
                <input type="search" value={input} placeholder='Search...' onChange={(evt)=>setInput(evt.target.value)}/>  
                <button id="addbutton" onClick={add}>Add</button>  
            </div>
            <div className="main">
                <Movies value={input}/>
            </div>       
        </div>)
}

export default Search;