#include <iostream>
#include <memory>
#include <string>

// ----------------- SRP: Report and ReportGenerator -----------------

class Report {
    std::string title;
    std::string content;
public:
    Report(const std::string& title, const std::string& content)
        : title(title), content(content) {}

    std::string getTitle() const { return title; }
    std::string getContent() const { return content; }
};

class ReportGenerator {
public:
    std::unique_ptr<Report> generate() {
        return std::make_unique<Report>("Monthly Report", "This is the content of the report.");
    }
};

// ------------- OCP + DIP: IReportSaver interface & implementations -------------

class IReportSaver {
public:
    virtual void save(const Report& report) = 0;
    virtual ~IReportSaver() = default;
};

class PDFReportSaver : public IReportSaver {
public:
    void save(const Report& report) override {
        std::cout << "Saving report to PDF: " << report.getTitle() << "\n";
    }
};

class DatabaseReportSaver : public IReportSaver {
public:
    void save(const Report& report) override {
        std::cout << "Saving report to database: " << report.getTitle() << "\n";
    }
};

// ------------------ LSP: Both savers can be used interchangeably ------------------
// Already applied as both save implementations follow the same interface contract.

// ------------------ ISP: Separate interfaces if needed ------------------
// Not needed in this scope, but we could have ISaver, ILoader, etc. if required.

// ------------------ DIP: High-level Application depends on abstractions ------------------

class Application {
    ReportGenerator generator;
    std::unique_ptr<IReportSaver> saver;
public:
    Application(std::unique_ptr<IReportSaver> saverImpl)
        : saver(std::move(saverImpl)) {}

    void run() {
        auto report = generator.generate();
        saver->save(*report);
    }
};

// ------------------ main() ------------------

int main() {
    // Use PDF saver
    auto pdfSaver = std::make_unique<PDFReportSaver>();
    Application app1(std::move(pdfSaver));
    app1.run();

    // Use Database saver
    auto dbSaver = std::make_unique<DatabaseReportSaver>();
    Application app2(std::move(dbSaver));
    app2.run();

    return 0;
}
