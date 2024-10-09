The Dependency Inversion Principle (DIP) states:

High-level modules (or classes) should not depend on low-level modules. Both should depend on abstractions (interfaces).
Abstractions should not depend on details. Details should depend on abstractions.

class Payment
{
    CreditCardBillPayment cbpayment;
    void pay(string acc, int money)
    {
        cbpayment.processPayment(//....logic);
    }
};

Now if in future you want to change payment method to DebitCardBillPayment or PayPalBillPayment, you would have to change the Payment class

It would have been better if we had loose coupling 

class BillPayer
{
   virtual void processPayment(//....logic)=0;
};

class CreditCardBillPayment :public BillPayer
{
    void processPayment(//....logic);
};

class DebitCardBillPayment :public BillPayer
{
    void processPayment(//....logic);
};

class Payment
{
    BillPayer cbpayment;
    void pay(string acc, int money)
    {
        cbpayment.processPayment(//....logic);
    }
};

Now payment class is loosely coupled with the help of abstraction BillPayer