import React, { useState } from "react";

const FeedbackSystem = () => {

  const [parameters, setParameters] = useState([
    {
      title : "Readability",
      upvote : 0,
      downvote: 0
    },
    { title: "Performance",
      upvote: 0,
      downvote: 0
    },
      { title: "Security",
      upvote: 0,
      downvote: 0
      },
    { title: "Documentation",
      upvote: 0,
      downvote: 0 
    },
    { title: "Testing",
      upvote: 0,
      downvote: 0 
    },  
  ])

    const handleUpvote = (title) => {
    setParameters((prev) =>
      prev.map((item) =>
        item.title === title
          ? { ...item, upvote: item.upvote + 1 }
          : item )
    );
  };

  const handleDownvote = (title) => {
    setParameters((prev) =>
      prev.map((item) =>
        item.title === title
          ? { ...item, downvote: item.downvote + 1 }
          : item )
    );
  };

  return (
    <div className="my-0 mx-auto text-center w-mx-1200">
      <div className="flex wrap justify-content-center mt-30 gap-30">
        {parameters.map((data, index) => (
        <div key={index} className="pa-10 w-300 card">
          <h2>{data.title}</h2>
          <div className="flex my-30 mx-0 justify-content-around">
            <button className="py-10 px-15" data-testid={`upvote-btn-${index}`}
                onClick={() => handleUpvote(data.title)}
            >
              👍 Upvote
            </button>
            <button className="py-10 px-15 danger" data-testid={`downvote-btn-${index}`}
                onClick={() => handleDownvote(data.title)}
            >
              👎 Downvote
            </button>
          </div>
          <p className="my-10 mx-0" data-testid={`upvote-count-${index}`}>
            Upvotes: <strong>{data.upvote}</strong>
          </p>
          <p className="my-10 mx-0" data-testid={`downvote-count-${index}`}>
            Downvotes: <strong>{data.downvote}</strong>
          </p>
        </div>
      ))}
      </div>
    </div>
  );
};

export default FeedbackSystem;
