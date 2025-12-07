#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

// CLASS: DrugRecord
// Represents one row from the dataset using:
// Patient_ID, Age, Drug_Name, Dosage_mg, Improvement_Score

class DrugRecord {
private:
    string patientID;
    int age;
    string drugName;
    int dosage_mg;
    int improvementScore;

public:
    DrugRecord(string id, int a, string drug, int dose, int score)
        : patientID(id), age(a), drugName(drug), dosage_mg(dose), improvementScore(score) {
    }

    void print() const {
        cout << "Patient ID: " << patientID << endl;
        cout << "Age: " << age << endl;
        cout << "Drug Name: " << drugName << endl;
        cout << "Dosage (mg): " << dosage_mg << endl;
        cout << "Improvement Score: " << improvementScore << endl;
        cout << "------------------------------------------------------\n";
    }

    // Getters for summary
    int getAge() const { return age; }
    int getDosage() const { return dosage_mg; }
    int getImprovement() const { return improvementScore; }
};

// Validate numeric strings before conversion

bool isNumber(const string& s) {
    if (s.empty()) return false;
    for (char c : s)
        if (!isdigit(static_cast<unsigned char>(c))) return false;
    return true;
}

// CLASS: DrugDataset
// Loads CSV, stores records, displays them, and prints summary.
class DrugDataset {
private:
    vector<DrugRecord> records;

public:

    void loadCSV(const string& filename) {
        ifstream file(filename);

        if (!file.is_open()) {
            cerr << "Error: Could not open file: " << filename << endl;
            return;
        }

        string line;
        bool skipHeader = true;

        while (getline(file, line)) {

            if (skipHeader) { skipHeader = false; continue; }

            stringstream ss(line);
            string col;
            vector<string> fields;

            while (getline(ss, col, ',')) fields.push_back(col);

            // Should match your exact 9-column dataset
            if (fields.size() < 9) continue;

            // Ensure numeric fields are valid
            if (!isNumber(fields[1]) ||  // Age
                !isNumber(fields[5]) ||  // Dosage_mg
                !isNumber(fields[8]))    // Improvement_Score
                continue;

            // Correct column indexing
            string patientID = fields[0];
            int age = stoi(fields[1]);
            string drugName = fields[4];      // FIXED
            int dosage = stoi(fields[5]);
            int improvement = stoi(fields[8]);

            // Store the record
            records.emplace_back(patientID, age, drugName, dosage, improvement);
        }

        file.close();
    }

    void displayRecords() const {
        cout << "\n=========== PATIENT DRUG RECORDS ===========\n\n";
        for (const auto& record : records)
            record.print();
    }

    void summarize() const {
        if (records.empty()) return;

        double totalAge = 0.0;
        double totalDosage = 0.0;
        double totalImprovement = 0.0;

        for (const auto& r : records) {
            totalAge += r.getAge();
            totalDosage += r.getDosage();
            totalImprovement += r.getImprovement();
        }

        double n = static_cast<double>(records.size());

        cout << "\n============= SUMMARY =============\n";
        cout << "Total records: " << records.size() << endl;
        cout << "Average Age: " << (totalAge / n) << endl;
        cout << "Average Dosage (mg): " << (totalDosage / n) << endl;
        cout << "Average Improvement Score: " << (totalImprovement / n) << endl;
    }           
};

int main() {
    DrugDataset dataset;
    dataset.loadCSV("real_drug_dataset.csv");
    dataset.displayRecords();
    dataset.summarize();
    return 0;
}
