1. Single Responsibility Principle (SRP)
Definition: A class should have one, and only one, reason to change, meaning it should have only one job or responsibility. This principle helps to reduce the complexity of code and makes it easier to understand and maintain.

class Report{
    void generateReport();
    void saveToFile(const std::string &filename);
};

Instead above way where Report class has two responsiblities 1 Generating report 2 Saving Report, use below

class Report{
    void generateReport();
};

class ReportSaver
{
    static void saveToFile(Report& report,const std::string &filename);
}

Now every class has only one reasin to change
