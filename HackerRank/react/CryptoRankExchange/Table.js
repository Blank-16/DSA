import React from "react";
import { cryptocurrencyList } from "../cryptocurrency-list";

const Consts = {
  InValidAmountError: "n/a",
  CoinDigits: 8
}

function Table({amount, isInvalid}) {  
  return (
    <div className="card card-text mt-10 mx-4">
      <table className="mb-0">
        <thead>
          <tr>
            <th>Cryptocurrency</th>
            <th>Exchange Rate</th>
            <th>Number of Coins</th>
          </tr>
        </thead>
        <tbody data-testid="exchange-data">
          {
            cryptocurrencyList.map((crypt, i) => {
              // Amount * Exchange Rate ( 8 decimal places )
              const numberOfCoin = (amount * crypt.rate).toFixed(Consts.CoinDigits);
              return (
                <tr
                  key={i}
                >
                  <td>{crypt.name}</td>
                  <td>1 USD = {crypt.rate} {crypt.code}</td>
                  <td>{
                    isInvalid 
                      ? Consts.InValidAmountError
                      : numberOfCoin
                    }</td>
                </tr>
              );
            })
          }
        </tbody>
      </table>
    </div>
  );
}

export default Table;
