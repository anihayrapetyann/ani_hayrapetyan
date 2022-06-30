import React, {useState} from 'react';
import MoviesList from './Movies';

function Search () {
    const[change, setChange] = useState("");
    return (
        <div>
            <input id="input" value = {change} type="search" placeholder="Search" onChange={(event)=>setChange(event.target.value)}/>
            <MoviesList value={change}/>
        </div>
    )
}

export default Search;