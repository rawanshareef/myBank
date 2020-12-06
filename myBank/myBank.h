#ifndef MYBANK_H
#define MYBANK_H


  void OpenNewAccount(double amount);
  void CheckAccount(int account_number);
  void deposit(int account_number,double amount);
  void CashWithdrawal(int account_number,double amount);
  void AccountClosing(int account_number);
  void AddInterest(double rate);
  void PrintAll();
  void CloseAllAccountes();

#endif