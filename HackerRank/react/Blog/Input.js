import React, { useState } from "react";

function Input({title, description, setTitle, setDescription}) {

  const handleChange = (e) => {
   if(e.target.name === "title"){
    setTitle(e.target.value)
   }else{
    setDescription(e.target.value)
   }

  }

  return (
    <div className="layout-column justify-content-center align-items-center">
      <input className="w-100" type="text" name="title" placeholder="Enter Title" value={title} onChange={handleChange} data-testid="title-input" />
      <textarea className="mt-10 w-100" name="description" placeholder="Enter Description" value={description} onChange={handleChange} data-testid="description-input" />
    </div>
  );
}

export default Input;
