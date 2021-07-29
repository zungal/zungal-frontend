import React from 'react';
import Login from "./Login";
import{BrowserRouter,Switch,Route} from 'react-router-dom';



class App extends React.Component {
  render(){

  return (
 <BrowserRouter>
 <Switch>
   <Route exact path={Login} />
 </Switch>
 
 </BrowserRouter>
   
  )
  }
  
}

export default App;
