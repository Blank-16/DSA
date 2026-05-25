import React from "react";
import Table from "./Table";

const Consts = {
  EmptyError: "Amount cannot be empty",
  LessAmountError: "Amount cannot be less than $0.01",
  OverAmountError: "Amount cannot exceed the available balance",
  MinimumAmount: 0.01,
  AvailableBalance: 17042.67,
}

function Main() {
  const [amount, setAmount] = React.useState(null);
  const [errorMsg, setErrorMsg] = React.useState(undefined);
  const handleInputAmount = (e) => {
    // if invalid, show an error message
    setErrorMsg("");
    const inputedAmount = e.currentTarget.value;
    if(!inputedAmount){
      setErrorMsg(Consts.EmptyError);
    } else if(inputedAmount <= Consts.MinimumAmount){
      setErrorMsg(Consts.LessAmountError);
    } else if(inputedAmount > Consts.AvailableBalance) {
      setErrorMsg(Consts.OverAmountError);
    } else {
      setAmount(inputedAmount);
    }
  };

  return (
    <div className="layout-column align-items-center mx-auto">
      <h1>CryptoRank Exchange</h1>
      <section>
        <div className="card-text layout-column align-items-center mt-12 px-8 flex text-center">
          <label>
            I want to exchange $ 
              <input 
                className="w-10"
                data-testid="amount-input"
                required
                type="number"
                placeholder="USD"
                onChange={(e) => handleInputAmount(e)}
                value={amount} 
              /> of my $
            <span>{Consts.AvailableBalance}</span>:
          </label>
          {
            errorMsg &&
              <p 
                data-testid="error"
                className="form-hint error-text mt-3 pl-0 ml-0"
              >
              {errorMsg}
            </p>
          }
          {/* The errors can be Amount cannot be empty /be less than $0.01/exceed the available balance */}
        </div>
      </section>
      <Table 
        amount={amount}
        isInvalid={!!errorMsg}
      />
    </div>
  );
}

export default Main;
