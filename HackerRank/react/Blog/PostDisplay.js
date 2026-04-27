import React from "react";

function PostDisplay({ blogData, handleDelete }) {

  return (
    <>
      {blogData?.length !== 0 && blogData?.map((blog) => {
        return <div className="post-box" key={blog?.id}>
          <h3>{blog?.title}</h3>
          <p>{blog?.description}</p>
          <button onClick={() => { handleDelete(blog?.id) }}>Delete</button>
        </div>
      })}
    </>
  );
}

export default PostDisplay;
