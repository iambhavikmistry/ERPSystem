#include<iostream>
#include<string>
using namespace std;

class item
{
private:
    int product_code;
    string item_name;
    float cost_price;
    float selling_price;
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
    void setCostPrice(float icprice)
    {
        cost_price=icprice;
    }
    void setSellPrice(float isprice)
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
    void ViewItem()
    {
        cout<<"\n\t"<<product_code<<"\t"<<item_name<<"\t"<<selling_price<<"\t"<<quantity;
    }
};
class cart
{
public :
    item cartItem[10];
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
public :
    void setcustomerId(int cid)
    {
        CustomerID=cid;
    }
    void setcustomerName(string cname)
    {
        CustomerName=cname;
    }
    void setcustomerContactNumber(int ccn)
    {
        CustomerContactNumber=ccn;
    }
    void setcustomerAddress(string caddress)
    {
        CustomerAddress=caddress;
    }
    void displayCustomer()
    {
        cout<<"\n\tCustomer Id : "<<CustomerID<<"\n\tCustomer Name : "<<CustomerName<<"\n\tCustomer's Contact Number : "<<"\n\tCustomer's Address : "<<CustomerAddress<<endl;
    }

};

class allCustomers
{
protected:
    customer customers[10];
};

class store : public inventory, public allCustomers,public cart
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
            cout<<">>>>>>>>>>>>>>>\nSelect Option : ";
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
        cout<<"\n\tCode\tName\tPrice\tAvailable Que.";
        for(int j=0; j<itemCounter; j++)
            products[j].ViewItem();
    }

    void bill()
    {
        displayItem();
    }
    void addItem()
    {
        string itemName;
        float itemSellingPrice;
        float itemCostPrice;
        int itemQuantity;

        cout<<"Enter Item Name : ";
        cin>>itemName;
        cout<<"Enter Item Selling Price (Single Unit): ";
        cin>>itemSellingPrice;
        cout<<"Enter Item Cost Price (Single Unit): ";
        cin>>itemCostPrice;
        cout<<"Enter Item Quantity : ";
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
        int flagSearch=0;

        cout<<"Enter Product Code : ";
        cin>>selectItemNumber;
         for(int i=0; i<itemCounter; i++)
        {
            if(selectItemNumber==i)
            {
                flagSearch=1;
                break;
            }
        }
        if(flagSearch==1)
        {
        cout<<"\n\n\t1.Update Name\n\t2.Update Selling Price\n\t3.Update Cost Price\n\t4.Update Item Quantity";
        cout<<"\nSelect Option : ";
        cin>>updateOption;

        switch(updateOption)
        {
        case 1:
        {
            cout<<"Update Item Name : ";
            cin>>updateItemName;
            products[selectItemNumber].setItemName(updateItemName);
        }
        break;

        case 2:
        {
            cout<<"Update Item Selling Price (Single Unit): ";
            cin>>updateItemSellingPrice;
            products[selectItemNumber].setSellPrice(updateItemSellingPrice);
        }
        break;

        case 3:
        {
            cout<<"Update Item Cost Price (Single Unit): ";
            cin>>updateItemCostPrice;
            products[selectItemNumber].setCostPrice(updateItemCostPrice);
        }
        break;
        case 4:
        {
            cout<<"Update Item Quantity : ";
            cin>>updateItemQuantity;
            products[selectItemNumber].setQuantity(updateItemQuantity);

        }
        break;
        default :
            cout<<"You've Selected Invalid Option"<<endl;

        }
        }
        else
        {
            cout<<"\n\n\t\t404-Product(Item) Not Found...";
        }


    }
    void searchItem()
    {
        int sItemCode,flagSearch=0;
        cout<<"Enter Product Code (Item Code) : ";
        cin>>sItemCode;

        for(int i=0; i<itemCounter; i++)
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
        string customerName;
        int customerContactNumber;
        string customerAddress;

        cout<<"Enter Customer Name : ";
        cin>>customerName;
        cout<<"Enter Customer's Contact Number : ";
        cin>>customerContactNumber;
        cout<<"Enter Customer's Address : ";
        cin>>customerAddress;

        customers[customerCounter].setcustomerId(customerCounter);
        customers[customerCounter].setcustomerName(customerName);
        customers[customerCounter].setcustomerContactNumber(customerContactNumber);
        customers[customerCounter].setcustomerAddress(customerAddress);
        customerCounter++;

    }
    void displayAllCustomers()
    {
        for(int i=0; i<customerCounter; i++)
        {
            customers[i].displayCustomer();
        }
    }
    void searchCustomers()
    {
        int scID,flagCustomerSearch=0;
        cout<<"Enter Customer ID : ";
        cin>>scID;
        for(int i=0; i<customerCounter; i++)
        {
            if(scID==i)
            {
                flagCustomerSearch=1;
                break;
            }
        }
        if(flagCustomerSearch==1)
        {
            customers[scID].displayCustomer();
        }
        else
        {
            cout<<"\n\n\t\t404-Customer Not Found...";
        }
    }

};



main()
{

    store manager;
    manager.cases();
}
