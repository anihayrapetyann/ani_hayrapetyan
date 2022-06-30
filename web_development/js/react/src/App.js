import './App.css';
import Search from './Input';
import MoviesList from './Movies';

function App() {
  // let value = document.querySelector('input');
  // console.log(value.value, "-----");
  return (
    <div className="App">
      <Search/>
      <MoviesList/>
    </div>
  );
}

export default App;
