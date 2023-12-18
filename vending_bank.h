/* Nithisha Sathishkumar
* October 13, 2023
* Project 1
* Professor.Dimpsey
*/

#ifndef VENDING_BANK_H_
#define VENDING_BANK_H_
#include <iostream>
#include <string>
using namespace std;

class VendingBank {
public:
  // constructor
  VendingBank();
  VendingBank(int id);
  VendingBank(int id, int quarter, int nickle, int dime, int penny, int total_coins_entered);

  // setters
  bool set_id(int id);
  bool set_quarter(int quarter);
  bool set_nickle(int nickle);
  bool set_dime(int dime);
  bool set_penny(int penny);
  bool set_total_coins_entered(int quarter, int nickle, int dime, int penny);
  bool setCoinValue(int quarter, int nickle, int dime, int penny,
                    int total_coins_entered);

  // getters
  int id() const;
  int quarters() const;
  int nickles() const;
  int dimes() const;
  int pennies() const;
  int total_coins() const;

  // Action
  //if money the user entered == product price then the purchase is success
  bool PurchaseSuccess(int value);

  //checks if the change are returned
  bool ReturnChange(int total_coins_entered) const;

  //check if the deposit coin is success
  bool DepositCoinSuccess(int quarter, int nickle, int dime, int penny);

  //checks if the refilling coin in the vending machine is success
  bool RefillingCoinSuccess(int quarter, int nickle, int dime, int penny);

  //check if there are enough coins in the vending machine
  bool EnoughCoinInBank(int quarter, int nickle, int dime, int penny);

  //check if there is a need of product refill
  bool NeedRefillProduct();

  //check if the cancel transaction is successful
  bool CancelTransactionSuccess();

  //check if the reset transaction is successful
  bool ResetTransactionSuccess();

  //check if the reset vending machine successful
  bool ResetVendingMachine();

  // Operator
  bool operator!=(VendingBank &value) const;
  bool operator==(VendingBank &value) const;
  VendingBank operator+(VendingBank const &value);
  VendingBank operator-(VendingBank const &value);
  VendingBank operator+=(VendingBank &value);
  VendingBank operator-=(VendingBank &value);

  // Stream I/O
  friend ostream &operator<<(ostream cout, VendingBank &value);
  friend istream &operator>>(istream cin, VendingBank &value);

  private:
  //private data members 
  int id_;
  int quarter_;
  int nickle_;
  int dime_;
  int penny_;
  int total_coins_entered_;
};

#endif