//
//  main.cpp
//  Assignment1
//
//  Created by Ansh Kumar Khalasi on 2/27/20.
//  Copyright © 2020 Ansh Kumar Khalasi. All rights reserved.
//

#include <iostream>
#include <string>



class Item {
    public:
        float unitCost;
        float unitPrice;
        float unitSold;
        float profit;
        
        float calculateProfit() {
            profit = (unitPrice - unitCost)*unitSold;
            return profit;
        }
    
};



int main() {
    Item item1;
    Item item2;
    Item item3;
    Item item4;
    Item item5;
    
    item1.unitCost = 3.23;
    item1.unitPrice = 4.25;
    item1.unitSold = 100;
    
    item2.unitCost = 4.12;
    item2.unitPrice = 5.28;
    item2.unitSold = 150;
    
    item3.unitCost = 10.54;
    item3.unitPrice = 12;
    item3.unitSold = 30;
    
    item4.unitCost = 5.61;
    item4.unitPrice = 7.82;
    item4.unitSold = 50;
    
    item5.unitCost = 7.45;
    item5.unitPrice = 8.76;
    item5.unitSold = 100;
    
    item1.profit = item1.calculateProfit();
    item2.profit = item2.calculateProfit();
    item3.profit = item3.calculateProfit();
    item4.profit = item4.calculateProfit();
    item5.profit = item5.calculateProfit();
    
    float dep1Profit = item1.profit + item2.profit;
    float dep2Profit = item3.profit + item4.profit + item5.profit;
    
    float companyProfit = dep1Profit + dep2Profit;
    
    std::cout << "Item 1 Profits: " << item1.profit << "\n";
    std::cout << "Item 2 Profits: " << item2.profit << "\n";
    std::cout << "Department 1 Profits: " << dep1Profit << "\n\n";
    std::cout << "Item 3 Profits: " << item3.profit << "\n";
    std::cout << "Item 4 Profits: " << item4.profit << "\n";
    std::cout << "Item 5 Profits: " << item5.profit << "\n";
    std::cout << "Department 2 Profits: " << dep2Profit << "\n\n";
    std::cout << "Company Profits: " << companyProfit << "\n";
    
}
