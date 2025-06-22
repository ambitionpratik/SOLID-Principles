class Report {
public:
    void generateReport() { /* logic to generate report */ }
    void saveToFile() { /* logic to save report to file */ }
};

// The above Report class violets the SRP. 
// The class is responsible for two operations.
// 1. Generating report
// 2. Saving it to file
// In the future if logic to generate report change or save to file change, then class will require modification.
// which causes violation of SRP.

class ReportGenerator {
public:
    void generateReport() { /* logic to generate report */ }
};
// There is only one reason to change, if report generation logic change. Only one responsibility of generating report.

class ReportSaver {
public:
    void saveToFile(const std::string& report) { /* logic to save */ }
};
// There is only one reason to change, if saving logic change. Only one responsibility of saving to file.
