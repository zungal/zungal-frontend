import React, { useState } from "react";
import Form from "react-bootstrap/Form";
import Button from "react-bootstrap/Button";
import './css/Login.css';


const Login = () => {
  const [username, setUsername] = useState("");
  const [password, setPassword] = useState("");

  function validateForm() {
    return username.length > 0 && password.length > 0;
  }

  function handleSubmit(event) {
    event.preventDefault();
  }

  
  return ( 
    <div className="TeacherLogin">
    
    <div className="Login">
    <div><h1>Teacher Login</h1></div>
      <Form onSubmit={handleSubmit}>
        <Form.Group size="lg" >
          
          <input className="input" placeholder="username"
          
            autoFocus
            type="text"
            value={username}
            
            onChange={(e) => setUsername(e.target.value)}
          />
        </Form.Group>
        <Form.Group size="lg" controlId="password">
          
          <input className="input" placeholder="password"
            type="password"
            value={password}
            onChange={(e) => setPassword(e.target.value)}
            
          />
        </Form.Group>
        <Button className="button" block size="lg" type="submit" disabled={!validateForm()}>
          Signin
        </Button>
      </Form>
    </div>
    </div>
  );
  
}

export default Login

  