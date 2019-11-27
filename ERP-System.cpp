#include<iostream>
#include<string>
using namespace std;

class item
{
private:
    int product_code;
    string item_name;
    int cost_price;
    int selling_price;
    int quantity;

public:
    void setProductCode(int icode)
    {
        product_code=icode;
    }
    void setItemName(string iname)
    {
        item_name=iname;
    }
    void setCostPrice(int icprice)
    {
        cost_price=icprice;
    }
    void setSellPrice(int isprice)
    {
        selling_price=isprice;
    }
    void setQuantity(int ique)
    {
        quantity=ique;
    }
    void displaySearchItem()
    {
        cout<<"\n\tProduct Code : "<<product_code<<"\n\t Product Name : "<<item_name<<"\n\t Product Selling Price : "<<selling_price<<"\n\t Product Cost Price : "<<cost_price<<"\n\t Quantity Of Products : "<<quantity;
    }

};

class inventory : public item
{
protected:

    item products[10];


};

class customer
{

private:
    int CustomerID;
    string CustomerName;
    int CustomerContactNumber;
    string CustomerAddress;

};

class allCustomers
{
protected:
    customer customers[10];
};
class store : public inventory, public allCustomers
{
public:
    int itemCounter=0;
    int customerCounter=0;
    void cases()
    {
        int flag=0;

        do
        {
            int option;
            storeDetails();
            cout<<"\n1.Create Bill : To Create BILL...\n2.Add Item : To Add New Item In Inventory...\n3.Update Item : To Update Existing Item In Inventory...\n4.Search Item : To Search Any Particular Item From Inventory...\n5.Add Customer : Add New Customer...\n6.Search Customer : Search A Particular Customer...\n7.All Customer : To Display All Customer...\n";
            cout<<"Select Option : ";
            cin>>option;
            switch(option)
            {
            case 1:
                bill();
                break;
            case 2:
                addItem();
                break;
            case 3:
                updateItem();
                break;
            case 4:
                searchItem();
                break;
            case 5:
                addCustomer();
                break;
            case 6:
                searchCustomers();
                break;
            case 7:
                displayAllCustomers();
                break;
            default :
                cout<<"You've Selected Invalid Option"<<endl;

            }

        }
        while(flag!=1);


    }
    void storeDetails()
    {
        cout<<"\n\n\t\t\tMafatLal Market\n\t\t    420-ChorBazaar Of India\n\t\t Contact Number : 99525-52420\n";
    }

    void displayItem()
    {

    }
    void bill()
    {

    }
    void addItem()
    {
        string itemName;
        int itemSellingPrice;
        int itemCostPrice;
        int itemQuantity;

        cout<<"Enter Item Name : "<<endl;
        cin>>itemName;
        cout<<"Enter Item Selling Price (Single Unit): "<<endl;
        cin>>itemSellingPrice;
        cout<<"Enter Item Cost Price (Single Unit): "<<endl;
        cin>>itemCostPrice;
        cout<<"Enter Item Quantity : "<<endl;
        cin>>itemQuantity;

        products[itemCounter].setProductCode(itemCounter);
        products[itemCounter].setItemName(itemName);
        products[itemCounter].setSellPrice(itemSellingPrice);
        products[itemCounter].setCostPrice(itemCostPrice);
        products[itemCounter].setQuantity(itemQuantity);
        itemCounter++;
    }
    void updateItem()
    {
        string updateItemName;
        int updateItemSellingPrice;
        int updateItemCostPrice;
        int updateItemQuantity;
        int updateOption;
        int selectItemNumber;

        cout<<"Enter Product Code : ";
        cin>>selectItemNumber;

        cout<<"\n\n1.Update Name\n\t2.Update Selling Price\n\t3.Update Cost Price\n\t4.Update Item Quantity";
        cin>>updateOption;

        switch(updateOption)
        {
        case 1:
        {
            cout<<"Update Item Name : "<<endl;
            cin>>updateItemName;
            products[selectItemNumber].setItemName(updateItemName);
        }
        break;

        case 2:
        {
            cout<<"Update Item Selling Price (Single Unit): "<<endl;
            cin>>updateItemSellingPrice;
            products[selectItemNumber].setSellPrice(updateItemSellingPrice);
        }
        break;

        case 3:
        {
            cout<<"Update Item Cost Price (Single Unit): "<<endl;
            cin>>updateItemCostPrice;
            products[selectItemNumber].setCostPrice(updateItemCostPrice);
        }
        break;
        case 4:
        {
            cout<<"Update Item Quantity : "<<endl;
            cin>>updateItemQuantity;
            products[selectItemNumber].setQuantity(updateItemQuantity);

        }
        break;
        default :
            cout<<"You've Selected Invalid Option"<<endl;

        }

    }
    void searchItem()
    {
        int sItemCode,flagSearch=0;
        cout<<"Enter Product Code (Item Code) : ";
        cin>>sItemCode;

        for(int i=0; i<=itemCounter; i++)
        {
            if(sItemCode==i)
            {
                flagSearch=1;
                break;

            }

        }
        if(flagSearch==1)
        {
            products[sItemCode].displaySearchItem();
        }
        else
        {
            cout<<"\n\n\t\t404-Product(Item) Not Found...";
        }

    }
    void addCustomer()
    {

    }
    void displayAllCustomers()
    {

    }
    void searchCustomers()
    {

    }

};
main()
{
    store manager;
    manager.cases();
}
