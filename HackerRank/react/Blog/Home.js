import React, { useState } from "react";
import Input from "./Input";
import PostDisplay from "./PostDisplay";


function Home() {
  const [blogData, setBlogData] = useState([])
  const [title, setTitle] = useState("")
  const [description, setDescription] = useState("")
  console.log("blogData", blogData)

  const saveBlog = () => {
    let num = Math.random();
    if (title?.trim() && description?.trim()) {
      setBlogData((prev) => [...prev, { id: num, title, description }])
      setTitle("")
      setDescription("")
    }
  }

   const handleDelete = (id) => {
    const filtedData = blogData?.filter((blog) => blog?.id !== id)
    setBlogData(filtedData)
  }

  return (
    <div className="text-center ma-20">
      <div className="mb-20">
        <Input title={title} description={description} setTitle={setTitle} setDescription={setDescription} />
        <button data-testid="create-button" className="mt-10" onClick={saveBlog}>
          Create Post
        </button>
      </div>
       <div className="posts-section">
        <div data-testid="posts-container" className="flex wrap gap-10">
        <PostDisplay blogData={blogData} handleDelete={handleDelete} />
        </div>
      </div>
    </div>
  );
}
export default Home
