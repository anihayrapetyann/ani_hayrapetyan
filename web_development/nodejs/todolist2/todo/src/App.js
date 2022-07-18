import Users from './Users';
import './App.css';
import React from 'react';
import {BrowserRouter, Routes, Route} from 'react-router-dom'
import Todos from './Todos';

function App() {
  return (
    <div className="App">
      <BrowserRouter>
      <Routes>
        <Route path="/" element={<Users/>} />
        <Route path="/users/:id" element={<Todos/>} />
      </Routes>
      </BrowserRouter>
    </div>
  );
}

export default App;
