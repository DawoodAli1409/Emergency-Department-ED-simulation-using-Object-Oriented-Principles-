#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <chrono>
#include <fstream>
#include <iostream>
#include <random>
#include <vector>
#include <cmath>

class Patient {
public:
    // Constructor with member initialization
    Patient() : category(0), typeOfBed("NULL"), timeOfBedAssignment(0),
        timeOfLabAssignment(0), Lab_Type("NULL"), treatment_plan(""),
        timeOfTreatment(0), doctor_type(""), treatment_type("NULL"),
        test_type("NULL"), Nurse(0), timeOfNurseAssignment(0),
        treatment_procedure("NULL"), timeOfProcedure(0) {
    }

    // Setters and Getters for Category
    void setCategory(int cat) { category = cat; }
    int getCategory() const { return category; }

    // Setters and Getters for Type of Bed
    void setTypeOfBed(const std::string& bedType) { typeOfBed = bedType; }
    std::string getTypeOfBed() const { return typeOfBed; }

    // Setters and Getters for Bed Assignment Time
    void setTimeOfBedAssignment(time_t time) { timeOfBedAssignment = time; }
    time_t getTimeOfBedAssignment() const { return timeOfBedAssignment; }

    // Setters and Getters for Lab Type
    void set_Lab_type(const std::string& type) { Lab_Type = type; }
    std::string get_Lab_type() const { return Lab_Type; }

    // Setters and Getters for Lab Assignment Time
    void setTimeOfLabAssignment(time_t time) { timeOfLabAssignment = time; }
    time_t getTimeOfLabAssignment() const { return timeOfLabAssignment; }

    // Setters and Getters for Treatment Time
    void setTimeOfTreatment(time_t time) { timeOfTreatment = time; }
    time_t getTimeOfTreatment() const { return timeOfTreatment; }

    // Setters and Getters for Treatment Plan
    void set_treatment_plan(const std::string& t_type) { treatment_plan = t_type; }
    std::string get_treatment_plan() const { return treatment_plan; }

    // Setters and Getters for Doctor Type
    void set_doctor_type(const std::string& dt) { doctor_type = dt; }
    std::string get_doctor_type() const { return doctor_type; }

    // Setters and Getters for Treatment Type
    void assign_treatment(const std::string& t) { treatment_type = t; }
    std::string get_treatment() const { return treatment_type; }

    // Setters and Getters for Test Type
    void set_test_type(const std::string& t) { test_type = t; }
    std::string get_test_type() const { return test_type; }

    // Setters and Getters for Nurse
    void assign_nurse(int t) { Nurse = t; }
    int get_nurse() const { return Nurse; }

    // Setters and Getters for Nurse Assignment Time
    void setTimeOfNurseAssignment(time_t time) { timeOfNurseAssignment = time; }
    time_t getTimeOfNurseAssignment() const { return timeOfNurseAssignment; }

    // Setters and Getters for Treatment Procedure
    void assign_treatment_procedure(const std::string& tp) { treatment_procedure = tp; }
    std::string get_procedure() const { return treatment_procedure; }

    // Setters and Getters for Procedure Assignment Time
    void setTimeOfProcedureAssignment(time_t time) { timeOfProcedure = time; }
    time_t getTimeOfProcedureAssignment() const { return timeOfProcedure; }

    // Integrating Flowchart Elements
    void setTransferToAltHosp(const TransferToAlternativeHospital& t) { transferToAltHosp = t; }
    TransferToAlternativeHospital getTransferToAltHosp() const { return transferToAltHosp; }

    void setObservationUnit(const ObservationUnit& o) { observationUnit = o; }
    ObservationUnit getObservationUnit() const { return observationUnit; }

    void setInpatientBed(const InpatientBed& i) { inpatientBed = i; }
    InpatientBed getInpatientBed() const { return inpatientBed; }

    void setHome(const Home& h) { home = h; }
    Home getHome() const { return home; }

    void setHospitalMorgue(const HospitalMorgue& h) { hospitalMorgue = h; }
    bool isExpired() const { return expired; }
    void setExpired(bool status) { expired = status; }
    HospitalMorgue getHospitalMorgue() const { return hospitalMorgue; }


private:
    int category;
    std::string typeOfBed;
    time_t timeOfBedAssignment;
    time_t timeOfLabAssignment;
    std::string Lab_Type;
    std::string treatment_plan;
    time_t timeOfTreatment;
    std::string doctor_type;
    std::string treatment_type;
    std::string test_type;
    int Nurse;
    time_t timeOfNurseAssignment;
    std::string treatment_procedure;
    time_t timeOfProcedure;
    bool expired = false;

};








class Bed {
public:
    void setAssignment(bool status) { assigned = status; }
    bool getStatus() const { return assigned; }

private:
    bool assigned = false;
};

class Doctor {
public:
    void setStatus(bool status) { available = status; }
    bool getStatus() const { return available; }



private:
    bool available = true;

};

class Queue {
public:
    void addPatient(const Patient& p) { patients.push_back(p); }
    bool isEmpty() const { return patients.empty(); }
    Patient getPatient() {
        if (!patients.empty()) {
            Patient p = patients.front();
            patients.erase(patients.begin());
            return p;
        }
        return Patient(); // Return empty patient if queue is empty
    }
    void printPatients() const {
        for (const auto& p : patients) {
            std::cout << "Patient Category: " << p.getCategory()
                << ", Bed Type: " << p.getTypeOfBed() << "\n";
        }
    }

private:
    std::vector<Patient> patients;
};

class Laboratory {
protected:
    bool is_lab_available;

public:
    Laboratory(bool ia = true, std::string t = "") :is_lab_available(ia) {};

    void set_lab_status(bool s) { is_lab_available = s; }

    bool get_lab_status() const { return is_lab_available; }



};

class Nursing {
private:
    bool is_nurse_available;
public:
    Nursing(bool ia = true) :is_nurse_available(ia) {};

    void set_nurse_status(bool s) { is_nurse_available = s; }

    bool get_nurse_status() const { return is_nurse_available; }
};

class Treatment_Procedure {
private:
    std::string procedure_type;
    bool is_procedure_available;
public:
    Treatment_Procedure(bool ia = true) :is_procedure_available(ia) {};

    void set_procedure_status(bool s) { is_procedure_available = s; }

    bool get_precedure_status() const { return is_procedure_available; }
    void set_procedure_type(std::string pt) { procedure_type = pt; }
    std::string get_procedure_type()const { return procedure_type; }


};

class TransferToAlternativeHospital {
public:
    TransferToAlternativeHospital() : transferred(false), transferTime(0) {}

    // Setter and Getter for transfer status
    void setTransferred(bool status) { transferred = status; }
    bool getTransferred() const { return transferred; }

    // Setter and Getter for transfer time
    void setTransferTime(time_t time) { transferTime = time; }
    time_t getTransferTime() const { return transferTime; }

private:
    bool transferred;
    time_t transferTime;
};

class ObservationUnit {
public:
    ObservationUnit() : admitted(false), admissionTime(0) {}

    // Setter and Getter for observation unit admission status
    void setAdmitted(bool status) { admitted = status; }
    bool getAdmitted() const { return admitted; }

    // Setter and Getter for observation unit admission time
    void setAdmissionTime(time_t time) { admissionTime = time; }
    time_t getAdmissionTime() const { return admissionTime; }

private:
    bool admitted;
    time_t admissionTime;
};

class InpatientBed {
public:
    InpatientBed() : assigned(false), assignmentTime(0) {}

    // Setter and Getter for inpatient bed assignment status
    void setAssigned(bool status) { assigned = status; }
    bool getAssigned() const { return assigned; }

    // Setter and Getter for inpatient bed assignment time
    void setAssignmentTime(time_t time) { assignmentTime = time; }
    time_t getAssignmentTime() const { return assignmentTime; }

private:
    bool assigned;
    time_t assignmentTime;
};

class Home {
public:
    Home() : discharged(false), dischargeTime(0) {}

    // Setter and Getter for home discharge status
    void setDischarged(bool status) { discharged = status; }
    bool getDischarged() const { return discharged; }

    // Setter and Getter for discharge time
    void setDischargeTime(time_t time) { dischargeTime = time; }
    time_t getDischargeTime() const { return dischargeTime; }

private:
    bool discharged;
    time_t dischargeTime;
};

class HospitalMorgue {
public:
    HospitalMorgue() : processed(false), processingTime(0) {}

    // Setter and Getter for morgue processing status
    void setProcessed(bool status) { processed = status; }
    bool getProcessed() const { return processed; }

    // Setter and Getter for morgue processing time
    void setProcessingTime(time_t time) { processingTime = time; }
    time_t getProcessingTime() const { return processingTime; }

private:
    bool processed;
    time_t processingTime;
};





double WD(double x, double k, double lambda) {
    if (x < 0)
        return 0.0;
    double term1 = (k / lambda);
    double term2 = pow((x / lambda), (k - 1));
    double term3 = exp((-pow((x / lambda), (k))));
    return term1 * term2 * term3;
}

double WIT(double scale, double shape) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    double U = dis(gen);
    return scale * pow(-log(1 - U), 1 / shape);
}

#include <cmath> // For std::exp

double PDDT(double x) {
    const double scale = 156.0; // Scale parameter
    return (1.0 / scale) * std::exp(-x / scale);
}
#include "Header1 (1).h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

void treatPatients(Bed* beds, int& bed_count, time_t ct, Doctor* doctors, int doctor_count, int pdt2, std::ofstream& dischargeFile)
{
    if (!beds || bed_count <= 0 || !doctors || doctor_count <= 0)
    {
        std::cerr << "Invalid input arrays or counts\n";
        return;
    }

    for (int i = 0; i < bed_count; i++)
    {
        if (beds[i].getStatus())
        { // Bed is occupied
            for (int j = 0; j < doctor_count; j++)
            {
                if (doctors[j].getStatus())
                { // Doctor is available
                    doctors[j].setStatus(false); // Mark as busy
                    beds[i].setAssignment(false); // Free the bed
                    bed_count--;
                    dischargeFile << "Patient treated at time: " << std::ctime(&ct) << std::endl;
                    break;
                }
            }
        }
    }
}


void ControlFlow()
{
    int Rbs = 10, Abs = 10, Sbs = 10, Mbs = 10;
    int idoctor = 10, jrdoctor = 10, rgsdoctor = 10, cdoctor = 10, srdoctor = 10;
    double shapearr[10] = { 0.914, 1.5, 1.2, 1.1, 1.6, 0.90, 1.3, 1.0, 1.1, 1.4 };
    auto current_time = std::chrono::system_clock::now();
    time_t ct = std::chrono::system_clock::to_time_t(current_time);
    time_t ct2 = std::chrono::system_clock::to_time_t(current_time);

    Queue Q1, Q2, Q3, Q4, Q5;
    Bed RB[10], AB[10], SB[10], MOPB[10], OFB[16];
    Doctor Consultants[10], Registrars[10], SeniorResidents[10], JuniorResidents[10], Interns[10];
    Laboratory X_Ray_Labs[10], MRI_Labs[10];
    Nursing nurse[100];
    Treatment_Procedure tp[5];
    std::vector<Patient> ptn;
    std::random_device rd;
    std::mt19937 gen(rd());
    int current_start = 0;

    // Open admission file outside the loop
    std::ofstream admissionFile("admission_time.txt", std::ios::app);
    if (!admissionFile)
    {
        std::cerr << "Error opening admission_time file!\n";
        return;
    }

    std::ofstream laboratoryFile("laboratory_time.txt", std::ios::app);
    if (!laboratoryFile)
    {
        std::cerr << "Error opening laboratory_time file!\n";
        return;
    }

    std::ofstream TreatmentFile("treatment_time.txt", std::ios::app);
    if (!TreatmentFile)
    {
        std::cerr << "Error opening Treatment_time file!\n";
        return;
    }

    std::ofstream NursingFile("nursing_time.txt", std::ios::app);
    if (!NursingFile)
    {
        std::cerr << "Error opening nursing_time file!\n";
        return;
    }

    std::ofstream ProcedureFile("procedure_time.txt", std::ios::app);
    if (!ProcedureFile)
    {
        std::cerr << "Error opening procedure_time file!\n";
        return;
    }

    // Declare file streams globally
    std::ofstream transferFile;
    std::ofstream observationFile;
    std::ofstream inpatientFile;
    std::ofstream homeFile;
    std::ofstream morgueFile;

    // Function to simulate writing Transfer to Alternative Hospital time
    void writeTransferToAlternativeHospitalTime(time_t time) {
        if (!transferFile.is_open()) {
            transferFile.open("transfer_to_alternative_hospital_time.txt", std::ios::app);
            if (!transferFile) {
                std::cerr << "Error opening transfer_to_alternative_hospital_time file!\n";
                return;
            }
        }
        transferFile << "Transfer Time: " << std::ctime(&time); // Writes time in human-readable format
    }

    // Function to simulate writing Observation Unit admission time
    void writeObservationUnitTime(time_t time) {
        if (!observationFile.is_open()) {
            observationFile.open("observation_unit_time.txt", std::ios::app);
            if (!observationFile) {
                std::cerr << "Error opening observation_unit_time file!\n";
                return;
            }
        }
        observationFile << "Observation Admission Time: " << std::ctime(&time);
    }

    // Function to simulate writing Inpatient Bed assignment time
    void writeInpatientBedTime(time_t time) {
        if (!inpatientFile.is_open()) {
            inpatientFile.open("inpatient_bed_time.txt", std::ios::app);
            if (!inpatientFile) {
                std::cerr << "Error opening inpatient_bed_time file!\n";
                return;
            }
        }
        inpatientFile << "Inpatient Bed Assignment Time: " << std::ctime(&time);
    }

    // Function to simulate writing Home discharge time
    void writeHomeTime(time_t time) {
        if (!homeFile.is_open()) {
            homeFile.open("home_time.txt", std::ios::app);
            if (!homeFile) {
                std::cerr << "Error opening home_time file!\n";
                return;
            }
        }
        homeFile << "Home Discharge Time: " << std::ctime(&time);
    }

    // Function to simulate writing Hospital Morgue processing time
    void writeHospitalMorgueTime(time_t time) {
        if (!morgueFile.is_open()) {
            morgueFile.open("hospital_morgue_time.txt", std::ios::app);
            if (!morgueFile) {
                std::cerr << "Error opening hospital_morgue_time file!\n";
                return;
            }
        }
        morgueFile << "Morgue Processing Time: " << std::ctime(&time);
    }





    while (current_start < 100)
    {
        // Random shape and scale generation
        std::uniform_int_distribution<> distrib(0, 9);
        int shaper = distrib(gen);
        double shape = shapearr[shaper];

        std::uniform_int_distribution<> distrib1(50, 320);
        double scale = distrib1(gen);

        // Probability and density calculation
        double probability = (WD(current_start, shape, scale)) * 1000;
        double density = (WIT(scale, shape)) / 10;

        ct += static_cast<time_t>(probability);
        Patient p;//patient comes
        if (density < 10) {
            for (int i = 0; i < 10; i++) {

                // ptn.push_back(p);
                p.setCategory(1); // Resuscitation Category
                if (!RB[i].getStatus()) {
                    RB[i].setAssignment(true); // Assign Resuscitation Bed
                    p.setTimeOfBedAssignment(ct);
                    p.setTypeOfBed("Resuscitation Bed");
                    admissionFile << "Patient admitted at: " << std::ctime(&ct) << "\n";
                    p.set_Lab_type("MRI");

                    //need to make Laboratory object
                    for (int i = 0; i < 10; i++)
                    {
                        if (MRI_Labs[i].get_lab_status())
                        {
                            p.set_test_type("MRI");
                            laboratoryFile << "MRI tests being conducted for category 1 patient at: " << std::ctime(&ct) << "\n";
                        }

                        else
                        {
                            laboratoryFile << "MRI Labs full." << std::endl;
                        }
                    }
                    p.set_doctor_type("SeniorResidents");
                    for (int i = 0; i < 10; i++)
                    {
                        if (SeniorResidents->getStatus())
                        {
                            p.assign_treatment("Emergency Surgery");
                            TreatmentFile << " Emergency Surgery being conducted for category 1 patient at: " << std::ctime(&ct) << "\n";

                        }
                        else
                        {
                            TreatmentFile << "All Senior Doctors are busy." << std::endl;
                        }
                    }
                    //assign nurse to patient
                    for (int i = 0; i < 10; i++)
                    {
                        if (nurse->get_nurse_status())
                        {
                            p.assign_nurse(i);
                            NursingFile << "Nurse alloted to hanle patient in Category 1 at:" << std::ctime(&ct);
                        }
                        else
                        {
                            NursingFile << "All Nurses are busy." << std::endl;
                        }


                    }
                    for (int i = 0; i < 10; i++)
                    {
                        if (tp->get_precedure_status())
                        {
                            p.assign_treatment_procedure("Suturing");
                            ProcedureFile << "Treatment procedure being carried out on patient of CAT 1 at:" << std::ctime(&ct);
                        }
                        else
                        {
                            ProcedureFile << "Treatment proceduer not available."; std::cout << std::endl;
                        }
                    }


                }
            }

            // Discharge Logic: Home
            if (p.getCategory() == 1 && p.getTypeOfBed() == "Resuscitation Bed" && !p.isExpired()) {
                if (p.getTimeOfTreatment() > 0 && p.getTimeOfTreatment() - p.getTimeOfBedAssignment() > 3600) { // Assuming 1 hour of treatment
                    p.setDischarged(true);
                    p.setDischargeTime(ct);
                    homeFile << "Patient discharged to home at: " << std::ctime(&ct) << "\n";
                    std::cout << "Patient discharged to home at: " << std::ctime(&ct) << "\n";
                }
            }

            // Transfer to Alternative Hospital
            if (p.getCategory() == 1 && !p.getDischarged() && p.getTypeOfBed() == "Resuscitation Bed" && !p.isExpired()) {
                if (p.getTimeOfTreatment() > 0 && p.getTimeOfTreatment() - p.getTimeOfBedAssignment() > 7200) { // 2 hours of treatment time
                    TransferToAlternativeHospital transfer; //creating transfer object to class 
                    transfer.setTransferred(true);
                    transfer.setTransferTime(ct);
                    p.setTransferToAltHosp(transfer);
                    transferFile << "Patient transferred to alternative hospital at: " << std::ctime(&ct) << "\n";
                    std::cout << "Patient transferred to alternative hospital at: " << std::ctime(&ct) << "\n";
                }
            }

            // Observation Unit Admission
            if (p.getCategory() == 1 && !p.getDischarged() && !p.getTransferred() && !p.isExpired()) {
                if (p.getTimeOfTreatment() > 0 && p.getTimeOfTreatment() - p.getTimeOfBedAssignment() > 1800) { // 30 minutes of treatment
                    ObservationUnit observation; //creating observation object to class
                    observation.setAdmitted(true);
                    observation.setAdmissionTime(ct);
                    p.setObservationUnit(observation);
                    observationUnitFile << "Patient admitted to Observation Unit at: " << std::ctime(&ct) << "\n";
                    std::cout << "Patient admitted to Observation Unit at: " << std::ctime(&ct) << "\n";
                }

            }
            // Check for Expired Patient
            if (p.isExpired()) {
                // If the patient is expired, send them to the morgue
                HospitalMorgue morgue;  //creating morgue object to class
                morgue.setProcessed(true);
                morgue.setProcessingTime(ct);
                p.setHospitalMorgue(morgue);
                morgueFile << "Patient processed at morgue at: " << std::ctime(&ct) << "\n";
                std::cout << "Patient processed at morgue at: " << std::ctime(&ct) << "\n";
            }


        }
    }


    //ptn.push_back(p);
    break;


    //tratment planning and senior doctor consult

    // If no beds are available, queue the patient
    p.setTimeOfBedAssignment(ct);
    p.setTypeOfBed("Queued!");
    // ptn.push_back(p);
    Q1.addPatient(p); // Add to the Resuscitation queue
    break;

}


        else if (density >= 10 && density < 20) {
    for (int i = 0; i < 10; i++) {
        p.setCategory(2); // Acute Category
        if (!AB[i].getStatus()) {
            AB[i].setAssignment(true); // Assign Acute Bed
            p.setTimeOfBedAssignment(ct);
            p.setTypeOfBed("Acute Bed");
            admissionFile << "Patient admitted at: " << std::ctime(&ct) << "\n";
            p.set_Lab_type("MRI");
            for (int i = 0; i < 10; i++)
            {
                if (MRI_Labs[i].get_lab_status())

                {
                    p.set_test_type("MRI");
                    laboratoryFile << "MRI tests being conducted for category 2 patient at: " << std::ctime(&ct) << "\n";
                }
                else
                {
                    laboratoryFile << "Labs full." << std::endl;
                }
            }
            p.set_doctor_type("SeniorResidents");

            for (int i = 0; i < 10; i++)
            {
                if (SeniorResidents->getStatus())
                {
                    p.assign_treatment("Preparation for potential surgery");
                    TreatmentFile << " Preparation for potential surgery  conducted for category 2 patient at: " << std::ctime(&ct) << "\n";


                }
                else
                {
                    TreatmentFile << "All Senior Doctors are busy." << std::endl;
                }

            }
            //assign nurse to patient
            for (int i = 0; i < 100; i++)
            {
                if (nurse->get_nurse_status())
                {
                    p.assign_nurse(i);
                    NursingFile << "Nurse alloted to hanle patient in Category 2 at:" << std::ctime(&ct);
                }
                else
                {
                    NursingFile << "All Nurses are busy." << std::endl;
                }


            }

            for (int i = 0; i < 10; i++)
            {
                if (tp->get_precedure_status())
                {
                    p.assign_treatment_procedure("Electrocardiogram (ECG)");
                    ProcedureFile << "Treatment procedure being carried out on patient of CAT 2 at:" << std::ctime(&ct);
                }
                else
                {
                    ProcedureFile << "Treatment procedure not available."; std::cout << std::endl;
                }
            }



        }

        // Discharge Logic: Home
        if (p.getCategory() == 2 && p.getTypeOfBed() == "Acute Bed" && !p.isExpired()) {
            if (p.getTimeOfTreatment() > 0 && p.getTimeOfTreatment() - p.getTimeOfBedAssignment() > 3600) { // Assuming 1 hour of treatment
                p.setDischarged(true);
                p.setDischargeTime(ct);
                homeFile << "Patient discharged to home at: " << std::ctime(&ct) << "\n";
                std::cout << "Patient discharged to home at: " << std::ctime(&ct) << "\n";
            }
        }

        // Transfer to Alternative Hospital
        if (p.getCategory() == 2 && !p.getDischarged() && p.getTypeOfBed() == "Acute Bed" && !p.isExpired()) {
            if (p.getTimeOfTreatment() > 0 && p.getTimeOfTreatment() - p.getTimeOfBedAssignment() > 7200) { // 2 hours of treatment time
                TransferToAlternativeHospital transfer; //creating transfer object to class 
                transfer.setTransferred(true);
                transfer.setTransferTime(ct);
                p.setTransferToAltHosp(transfer);
                transferFile << "Patient transferred to alternative hospital at: " << std::ctime(&ct) << "\n";
                std::cout << "Patient transferred to alternative hospital at: " << std::ctime(&ct) << "\n";
            }
        }

        // Observation Unit Admission
        if (p.getCategory() == 2 && !p.getDischarged() && !p.getTransferred() && !p.isExpired()) {
            if (p.getTimeOfTreatment() > 0 && p.getTimeOfTreatment() - p.getTimeOfBedAssignment() > 1800) { // 30 minutes of treatment
                ObservationUnit observation; //creating observation object to class
                observation.setAdmitted(true);
                observation.setAdmissionTime(ct);
                p.setObservationUnit(observation);
                observationUnitFile << "Patient admitted to Observation Unit at: " << std::ctime(&ct) << "\n";
                std::cout << "Patient admitted to Observation Unit at: " << std::ctime(&ct) << "\n";
            }

        }
        // Check for Expired Patient
        if (p.isExpired()) {
            // If the patient is expired, send them to the morgue
            HospitalMorgue morgue;  //creating morgue object to class
            morgue.setProcessed(true);
            morgue.setProcessingTime(ct);
            p.setHospitalMorgue(morgue);
            morgueFile << "Patient processed at morgue at: " << std::ctime(&ct) << "\n";
            std::cout << "Patient processed at morgue at: " << std::ctime(&ct) << "\n";

            ptn.push_back(p);
            break;

            if (!SB[i].getStatus()) {
                SB[i].setAssignment(true); // Assign Subacute Bed
                p.setTimeOfBedAssignment(ct);
                p.setTypeOfBed("Subacute Bed");
                admissionFile << "Patient admitted at: " << std::ctime(&ct) << "\n";
                p.set_Lab_type("MRI");
                for (int i = 0; i < 10; i++)
                {
                    if (MRI_Labs[i].get_lab_status())
                    {
                        p.set_test_type("MRI");
                        laboratoryFile << "MRI tests being conducted for category 2 patient at: " << std::ctime(&ct) << "\n";
                    }
                    else
                    {
                        laboratoryFile << "Labs full." << std::endl;
                    }

                }
                p.set_doctor_type("SeniorResidents");
                for (int i = 0; i < 10; i++)
                {
                    if (SeniorResidents->getStatus())
                    {
                        p.assign_treatment("Preparation for potential surgery");
                        TreatmentFile << " Preparation for potential surgery being conducted for category 2 patient at: " << std::ctime(&ct) << "\n";


                    }
                    else
                    {
                        TreatmentFile << "All Senior Doctors are busy." << std::endl;
                    }
                }
                //assign nurse to patient
                for (int i = 0; i < 100; i++)
                {
                    if (nurse->get_nurse_status())
                    {
                        p.assign_nurse(i);
                        NursingFile << "Nurse alloted to hanle patient in Category 2 at:" << std::ctime(&ct);
                    }
                    else
                    {
                        NursingFile << "All Nurses are busy." << std::endl;
                    }


                }

                for (int i = 0; i < 10; i++)
                {
                    if (tp->get_precedure_status())
                    {
                        p.assign_treatment_procedure("Electrocardiogram (ECG)");
                        ProcedureFile << "Treatment procedure being carried out on patient of CAT 2 at:" << std::ctime(&ct);
                    }
                    else
                    {
                        ProcedureFile << "Treatment procedure not available."; std::cout << std::endl;
                    }
                }


            }

            // Discharge Logic: Home
            if (p.getCategory() == 2 && p.getTypeOfBed() == "Subacute Bed" && !p.isExpired()) {
                if (p.getTimeOfTreatment() > 0 && p.getTimeOfTreatment() - p.getTimeOfBedAssignment() > 3600) { // Assuming 1 hour of treatment
                    p.setDischarged(true);
                    p.setDischargeTime(ct);
                    homeFile << "Patient discharged to home at: " << std::ctime(&ct) << "\n";
                    std::cout << "Patient discharged to home at: " << std::ctime(&ct) << "\n";
                }
            }

            // Transfer to Alternative Hospital
            if (p.getCategory() == 2 && !p.getDischarged() && p.getTypeOfBed() == "Subacute Bed" && !p.isExpired()) {
                if (p.getTimeOfTreatment() > 0 && p.getTimeOfTreatment() - p.getTimeOfBedAssignment() > 7200) { // 2 hours of treatment time
                    TransferToAlternativeHospital transfer; //creating transfer object to class 
                    transfer.setTransferred(true);
                    transfer.setTransferTime(ct);
                    p.setTransferToAltHosp(transfer);
                    transferFile << "Patient transferred to alternative hospital at: " << std::ctime(&ct) << "\n";
                    std::cout << "Patient transferred to alternative hospital at: " << std::ctime(&ct) << "\n";
                }
            }

            // Observation Unit Admission
            if (p.getCategory() == 2 && !p.getDischarged() && !p.getTransferred() && !p.isExpired()) {
                if (p.getTimeOfTreatment() > 0 && p.getTimeOfTreatment() - p.getTimeOfBedAssignment() > 1800) { // 30 minutes of treatment
                    ObservationUnit observation; //creating observation object to class
                    observation.setAdmitted(true);
                    observation.setAdmissionTime(ct);
                    p.setObservationUnit(observation);
                    observationUnitFile << "Patient admitted to Observation Unit at: " << std::ctime(&ct) << "\n";
                    std::cout << "Patient admitted to Observation Unit at: " << std::ctime(&ct) << "\n";
                }

            }
            // Check for Expired Patient
            if (p.isExpired()) {
                // If the patient is expired, send them to the morgue
                HospitalMorgue morgue;  //creating morgue object to class
                morgue.setProcessed(true);
                morgue.setProcessingTime(ct);
                p.setHospitalMorgue(morgue);
                morgueFile << "Patient processed at morgue at: " << std::ctime(&ct) << "\n";
                std::cout << "Patient processed at morgue at: " << std::ctime(&ct) << "\n";

                ptn.push_back(p);
                break;

                if (!MOPB[i].getStatus()) {
                    MOPB[i].setAssignment(true); // Assign Minor Procedure Bed
                    p.setTimeOfBedAssignment(ct);
                    p.setTypeOfBed("Minor Procedure Bed");
                    admissionFile << "Patient admitted at: " << std::ctime(&ct) << "\n";
                    p.set_Lab_type("MRI");
                    for (int i = 0; i < 10; i++)
                    {
                        if (MRI_Labs[i].get_lab_status())
                        {
                            p.set_test_type("MRI");
                            laboratoryFile << "MRI tests being conducted for category 2 patient at: " << std::ctime(&ct) << "\n";
                        }
                        else
                        {
                            laboratoryFile << "Labs full." << std::endl;
                        }
                    }
                    p.set_doctor_type("SeniorResidents");
                    for (int i = 0; i < 10; i++)
                    {
                        if (SeniorResidents->getStatus())
                        {
                            p.assign_treatment(" Preparation for potential surgery");
                            TreatmentFile << " Preparation for potential surgery being conducted for category 2 patient at: " << std::ctime(&ct) << "\n";


                        }
                        else
                        {
                            TreatmentFile << "All Senior Doctors are busy." << std::endl;
                        }
                    }
                    //assign nurse to patient
                    for (int i = 0; i < 100; i++)
                    {
                        if (nurse->get_nurse_status())
                        {
                            p.assign_nurse(i);
                            NursingFile << "urse alloted to hanle patient in Category 2 at:" << std::ctime(&ct);
                        }
                        else
                        {
                            NursingFile << "All Nurses are busy." << std::endl;
                        }


                    }

                    for (int i = 0; i < 10; i++)
                    {
                        if (tp->get_precedure_status())
                        {
                            p.assign_treatment_procedure("Electrocardiogram (ECG)");
                            ProcedureFile << "Treatment procedure being carried out on patient of CAT 2 at:" << std::ctime(&ct);
                        }
                        else
                        {
                            ProcedureFile << "Treatment procedure not available."; std::cout << std::endl;
                        }
                    }

                    // Discharge Logic: Home
                    if (p.getCategory() == 2 && p.getTypeOfBed() == "Minor Procedure Bed" && !p.isExpired()) {
                        if (p.getTimeOfTreatment() > 0 && p.getTimeOfTreatment() - p.getTimeOfBedAssignment() > 3600) { // Assuming 1 hour of treatment
                            p.setDischarged(true);
                            p.setDischargeTime(ct);
                            homeFile << "Patient discharged to home at: " << std::ctime(&ct) << "\n";
                            std::cout << "Patient discharged to home at: " << std::ctime(&ct) << "\n";
                        }
                    }

                    // Transfer to Alternative Hospital
                    if (p.getCategory() == 2 && !p.getDischarged() && p.getTypeOfBed() == "Minor Procedure Bed" && !p.isExpired()) {
                        if (p.getTimeOfTreatment() > 0 && p.getTimeOfTreatment() - p.getTimeOfBedAssignment() > 7200) { // 2 hours of treatment time
                            TransferToAlternativeHospital transfer; //creating transfer object to class 
                            transfer.setTransferred(true);
                            transfer.setTransferTime(ct);
                            p.setTransferToAltHosp(transfer);
                            transferFile << "Patient transferred to alternative hospital at: " << std::ctime(&ct) << "\n";
                            std::cout << "Patient transferred to alternative hospital at: " << std::ctime(&ct) << "\n";
                        }
                    }

                    // Observation Unit Admission
                    if (p.getCategory() == 2 && !p.getDischarged() && !p.getTransferred() && !p.isExpired()) {
                        if (p.getTimeOfTreatment() > 0 && p.getTimeOfTreatment() - p.getTimeOfBedAssignment() > 1800) { // 30 minutes of treatment
                            ObservationUnit observation; //creating observation object to class
                            observation.setAdmitted(true);
                            observation.setAdmissionTime(ct);
                            p.setObservationUnit(observation);
                            observationUnitFile << "Patient admitted to Observation Unit at: " << std::ctime(&ct) << "\n";
                            std::cout << "Patient admitted to Observation Unit at: " << std::ctime(&ct) << "\n";
                        }

                    }
                    // Check for Expired Patient
                    if (p.isExpired()) {
                        // If the patient is expired, send them to the morgue
                        HospitalMorgue morgue;  //creating morgue object to class
                        morgue.setProcessed(true);
                        morgue.setProcessingTime(ct);
                        p.setHospitalMorgue(morgue);
                        morgueFile << "Patient processed at morgue at: " << std::ctime(&ct) << "\n";
                        std::cout << "Patient processed at morgue at: " << std::ctime(&ct) << "\n";



                        ptn.push_back(p);
                        break;
                    }
                    if (!OFB[i].getStatus()) {
                        OFB[i].setAssignment(true); // Assign Minor Procedure Bed
                        p.setTimeOfBedAssignment(ct);
                        p.setTypeOfBed("Overflow Bed");
                        admissionFile << "Patient admitted at: " << std::ctime(&ct) << "\n";
                        p.set_Lab_type("MRI");
                        for (int i = 0; i < 10; i++)
                        {
                            if (MRI_Labs[i].get_lab_status())
                            {
                                p.set_test_type("MRI");
                                laboratoryFile << "MRI tests being conducted for category 2 patient at: " << std::ctime(&ct) << "\n";
                            }
                            else
                            {
                                laboratoryFile << "Labs full." << std::endl;
                            }
                        }
                        p.set_doctor_type("SeniorResidents");
                        for (int i = 0; i < 10; i++)
                        {
                            if (SeniorResidents->getStatus())
                            {
                                p.assign_treatment("Preparation for potential surgery");
                                TreatmentFile << " Preparation for potential surgery being conducted for category 2 patient at: " << std::ctime(&ct) << "\n";


                            }
                            else
                            {
                                TreatmentFile << "All Senior Doctors are busy." << std::endl;
                            }
                        }
                        for (int i = 0; i < 100; i++)
                        {
                            if (nurse->get_nurse_status())
                            {
                                p.assign_nurse(i);
                                NursingFile << "urse alloted to hanle patient in Category 2 at:" << std::ctime(&ct);
                            }
                            else
                            {
                                NursingFile << "All Nurses are busy." << std::endl;
                            }


                        }

                        for (int i = 0; i < 10; i++)
                        {
                            if (tp->get_precedure_status())
                            {
                                p.assign_treatment_procedure("Electrocardiogram (ECG)");
                                ProcedureFile << "Treatment procedure being carried out on patient of CAT 2 at:" << std::ctime(&ct);
                            }
                            else
                            {
                                ProcedureFile << "Treatment procedure not available."; std::cout << std::endl;
                            }
                        }


                    }
                    // Discharge Logic: Home
                    if (p.getCategory() == 2 && p.getTypeOfBed() == "Overflow Bed" && !p.isExpired()) {
                        if (p.getTimeOfTreatment() > 0 && p.getTimeOfTreatment() - p.getTimeOfBedAssignment() > 3600) { // Assuming 1 hour of treatment
                            p.setDischarged(true);
                            p.setDischargeTime(ct);
                            homeFile << "Patient discharged to home at: " << std::ctime(&ct) << "\n";
                            std::cout << "Patient discharged to home at: " << std::ctime(&ct) << "\n";
                        }
                    }

                    // Transfer to Alternative Hospital
                    if (p.getCategory() == 2 && !p.getDischarged() && p.getTypeOfBed() == "Overflow Bed" && !p.isExpired()) {
                        if (p.getTimeOfTreatment() > 0 && p.getTimeOfTreatment() - p.getTimeOfBedAssignment() > 7200) { // 2 hours of treatment time
                            TransferToAlternativeHospital transfer; //creating transfer object to class 
                            transfer.setTransferred(true);
                            transfer.setTransferTime(ct);
                            p.setTransferToAltHosp(transfer);
                            transferFile << "Patient transferred to alternative hospital at: " << std::ctime(&ct) << "\n";
                            std::cout << "Patient transferred to alternative hospital at: " << std::ctime(&ct) << "\n";
                        }
                    }

                    // Observation Unit Admission
                    if (p.getCategory() == 2 && !p.getDischarged() && !p.getTransferred() && !p.isExpired()) {
                        if (p.getTimeOfTreatment() > 0 && p.getTimeOfTreatment() - p.getTimeOfBedAssignment() > 1800) { // 30 minutes of treatment
                            ObservationUnit observation; //creating observation object to class
                            observation.setAdmitted(true);
                            observation.setAdmissionTime(ct);
                            p.setObservationUnit(observation);
                            observationUnitFile << "Patient admitted to Observation Unit at: " << std::ctime(&ct) << "\n";
                            std::cout << "Patient admitted to Observation Unit at: " << std::ctime(&ct) << "\n";
                        }

                    }
                    // Check for Expired Patient
                    if (p.isExpired()) {
                        // If the patient is expired, send them to the morgue
                        HospitalMorgue morgue;  //creating morgue object to class
                        morgue.setProcessed(true);
                        morgue.setProcessingTime(ct);
                        p.setHospitalMorgue(morgue);
                        morgueFile << "Patient processed at morgue at: " << std::ctime(&ct) << "\n";
                        std::cout << "Patient processed at morgue at: " << std::ctime(&ct) << "\n";

                        ptn.push_back(p);
                        break;
                    }

                }

                // If no beds are available, queue the patient
                p.setTimeOfBedAssignment(ct);
                p.setTypeOfBed("Queued!");
                ptn.push_back(p);
                Q2.addPatient(p); // Add to the Acute queue
                break;
            }

            else if (density >= 20 && density < 30) {
                for (int i = 0; i < 10; i++) {
                    p.setCategory(3); // Subacute Category
                    if (!SB[i].getStatus()) {
                        SB[i].setAssignment(true); // Assign Subacute Bed
                        p.setTimeOfBedAssignment(ct);
                        p.setTypeOfBed("Subacute Bed");
                        admissionFile << "Patient admitted at: " << std::ctime(&ct) << "\n";
                        p.set_Lab_type("MRI");
                        for (int i = 0; i < 10; i++)
                        {
                            if (MRI_Labs[i].get_lab_status())
                            {
                                p.set_test_type("MRI");
                                laboratoryFile << "MRI tests being conducted for category 3 patient at: " << std::ctime(&ct) << "\n";
                            }
                            else
                            {
                                laboratoryFile << "Labs full." << std::endl;
                            }
                        }
                        p.set_doctor_type("SeniorResidents");
                        for (int i = 0; i < 10; i++)
                        {
                            if (SeniorResidents->getStatus())
                            {
                                p.assign_treatment("Monitoring vital signs and observation");
                                TreatmentFile << " Monitoring vital signs and observation being conducted for category 3 patient at: " << std::ctime(&ct) << "\n";


                            }
                            else
                            {
                                TreatmentFile << "All Senior Doctors are busy." << std::endl;
                            }
                        }
                        for (int i = 0; i < 100; i++)
                        {
                            if (nurse->get_nurse_status())
                            {
                                p.assign_nurse(i);
                                NursingFile << "urse alloted to hanle patient in Category 3 at:" << std::ctime(&ct);
                            }
                            else
                            {
                                NursingFile << "All Nurses are busy." << std::endl;
                            }


                        }


                        for (int i = 0; i < 10; i++)
                        {
                            if (tp->get_precedure_status())
                            {
                                p.assign_treatment_procedure("Critical care monitoring");
                                ProcedureFile << "Treatment procedure being carried out on patient of CAT 3 at:" << std::ctime(&ct);
                            }
                            else
                            {
                                ProcedureFile << "Treatment procedure not available."; std::cout << std::endl;
                            }
                        }






                        ptn.push_back(p);
                        break;
                    }
                    if (!MOPB[i].getStatus()) {
                        MOPB[i].setAssignment(true); // Assign Minor Procedure Bed
                        p.setTimeOfBedAssignment(ct);
                        p.setTypeOfBed("Minor Procedure Bed");
                        admissionFile << "Patient admitted at: " << std::ctime(&ct) << "\n";
                        p.set_Lab_type("MRI");
                        for (int i = 0; i < 10; i++)
                        {
                            if (MRI_Labs[i].get_lab_status())
                            {
                                p.set_test_type("MRI");
                                laboratoryFile << "MRI tests being conducted for category 3 patient at: " << std::ctime(&ct) << "\n";
                            }
                            else
                            {
                                laboratoryFile << "Labs full." << std::endl;
                            }
                        }
                        p.set_doctor_type("SeniorResidents");
                        for (int i = 0; i < 10; i++)
                        {
                            if (SeniorResidents->getStatus())
                            {
                                p.assign_treatment("Monitoring vital signs and observation");
                                TreatmentFile << " Monitoring vital signs and observation being conducted for category 3 patient at: " << std::ctime(&ct) << "\n";


                            }
                            else
                            {
                                TreatmentFile << "All Senior Doctors are busy." << std::endl;
                            }
                        }
                        for (int i = 0; i < 100; i++)
                        {
                            if (nurse->get_nurse_status())
                            {
                                p.assign_nurse(i);
                                NursingFile << "urse alloted to hanle patient in Category 3 at:" << std::ctime(&ct);
                            }
                            else
                            {
                                NursingFile << "All Nurses are busy." << std::endl;
                            }


                        }

                        for (int i = 0; i < 10; i++)
                        {
                            if (tp->get_precedure_status())
                            {
                                p.assign_treatment_procedure("Critical care monitoring");
                                ProcedureFile << "Treatment procedure being carried out on patient of CAT 3 at:" << std::ctime(&ct);
                            }
                            else
                            {
                                ProcedureFile << "Treatment procedure not available."; std::cout << std::endl;
                            }
                        }







                        ptn.push_back(p);
                        break;
                    }
                    if (!OFB[i].getStatus()) {
                        OFB[i].setAssignment(true); // Assign Minor Procedure Bed
                        p.setTimeOfBedAssignment(ct);
                        p.setTypeOfBed("Overflow Bed");
                        admissionFile << "Patient admitted at: " << std::ctime(&ct) << "\n";
                        p.set_Lab_type("MRI");
                        for (int i = 0; i < 10; i++)
                        {
                            if (MRI_Labs[i].get_lab_status())
                            {
                                // Labs[i].set_lab_status(true);
                                p.set_test_type("MRI");
                                laboratoryFile << "MRI tests being conducted for category 3 patient at: " << std::ctime(&ct) << "\n";
                            }
                            else
                            {
                                laboratoryFile << "Labs full." << std::endl;
                            }
                        }
                        p.set_doctor_type("SeniorResidents");
                        for (int i = 0; i < 10; i++)
                        {
                            if (SeniorResidents->getStatus())
                            {
                                p.assign_treatment("Monitoring vital signs and observation");
                                TreatmentFile << " Monitoring vital signs and observation being conducted for category 3 patient at: " << std::ctime(&ct) << "\n";


                            }
                            else
                            {
                                TreatmentFile << "All Senior Doctors are busy." << std::endl;
                            }
                        }
                        for (int i = 0; i < 100; i++)
                        {
                            if (nurse->get_nurse_status())
                            {
                                NursingFile << "urse alloted to hanle patient in Category 3 at:" << std::ctime(&ct);
                                p.assign_nurse(i);
                            }
                            else
                            {
                                NursingFile << "All Nurses are busy." << std::endl;
                            }


                        }

                        for (int i = 0; i < 10; i++)
                        {
                            if (tp->get_precedure_status())
                            {
                                p.assign_treatment_procedure("Critical care monitoring");
                                ProcedureFile << "Treatment procedure being carried out on patient of CAT 3 at:" << std::ctime(&ct);
                            }
                            else
                            {
                                ProcedureFile << "Treatment procedure not available."; std::cout << std::endl;
                            }
                        }





                    }



                    ptn.push_back(p);
                    break;
                }
                // If no beds are available, queue the patient
                p.setTimeOfBedAssignment(ct);
                p.setTypeOfBed("Queued!");
                ptn.push_back(p);
                Q3.addPatient(p); // Add to the Subacute queue
                break;
            }

            else if (density >= 30 && density < 40) {
                for (int i = 0; i < 10; i++) {
                    p.setCategory(4); // Minor Procedure Category
                    if (!MOPB[i].getStatus()) {
                        MOPB[i].setAssignment(true); // Assign Minor Procedure Bed
                        p.setTimeOfBedAssignment(ct);
                        p.setTypeOfBed("Minor Procedure Bed");
                        admissionFile << "Patient admitted at: " << std::ctime(&ct) << "\n";
                        p.set_Lab_type("X_Ray");
                        for (int i = 0; i < 10; i++)
                        {
                            if (X_Ray_Labs[i].get_lab_status())
                            {
                                p.set_test_type("X-Ray");
                                laboratoryFile << "X-Ray tests being conducted for category 4 patient at: " << std::ctime(&ct) << "\n";
                            }
                            else
                            {
                                laboratoryFile << "Labs full." << std::endl;
                            }
                        }
                        p.set_doctor_type("SeniorResidents");
                        for (int i = 0; i < 10; i++)
                        {
                            if (SeniorResidents->getStatus())
                            {
                                p.assign_treatment("Routine diagnostic test");
                                TreatmentFile << " Routine diagnostic test being conducted for category 4 patient at: " << std::ctime(&ct) << "\n";


                            }
                            else
                            {
                                TreatmentFile << "All Senior Doctors are busy." << std::endl;
                            }
                        }
                        for (int i = 0; i < 100; i++)
                        {
                            if (nurse->get_nurse_status())
                            {
                                p.assign_nurse(i);
                                NursingFile << "Nurse alloted to handle patient in Category 4 at:" << std::ctime(&ct);
                            }
                            else
                            {
                                NursingFile << "All Nurses are busy." << std::endl;
                            }


                        }

                        for (int i = 0; i < 10; i++)
                        {
                            if (tp->get_precedure_status())
                            {
                                p.assign_treatment_procedure("Physical Therapy exercise");
                                ProcedureFile << "Treatment procedure being carried out on patient of CAT 4 at:" << std::ctime(&ct);
                            }
                            else
                            {
                                ProcedureFile << "Treatment procedure not available."; std::cout << std::endl;
                            }
                        }


                        // Discharge Logic: Home
                        if (p.getCategory() == 2 && p.getTypeOfBed() == "Minor Procedure Bed" && !p.isExpired()) {
                            if (p.getTimeOfTreatment() > 0 && p.getTimeOfTreatment() - p.getTimeOfBedAssignment() > 3600) { // Assuming 1 hour of treatment
                                p.setDischarged(true);
                                p.setDischargeTime(ct);
                                homeFile << "Patient discharged to home at: " << std::ctime(&ct) << "\n";
                                std::cout << "Patient discharged to home at: " << std::ctime(&ct) << "\n";
                            }
                        }

                        // Transfer to Alternative Hospital
                        if (p.getCategory() == 2 && !p.getDischarged() && p.getTypeOfBed() == "Minor Procedure Bed" && !p.isExpired()) {
                            if (p.getTimeOfTreatment() > 0 && p.getTimeOfTreatment() - p.getTimeOfBedAssignment() > 7200) { // 2 hours of treatment time
                                TransferToAlternativeHospital transfer; //creating transfer object to class 
                                transfer.setTransferred(true);
                                transfer.setTransferTime(ct);
                                p.setTransferToAltHosp(transfer);
                                transferFile << "Patient transferred to alternative hospital at: " << std::ctime(&ct) << "\n";
                                std::cout << "Patient transferred to alternative hospital at: " << std::ctime(&ct) << "\n";
                            }
                        }

                        // Observation Unit Admission
                        if (p.getCategory() == 2 && !p.getDischarged() && !p.getTransferred() && !p.isExpired()) {
                            if (p.getTimeOfTreatment() > 0 && p.getTimeOfTreatment() - p.getTimeOfBedAssignment() > 1800) { // 30 minutes of treatment
                                ObservationUnit observation; //creating observation object to class
                                observation.setAdmitted(true);
                                observation.setAdmissionTime(ct);
                                p.setObservationUnit(observation);
                                observationUnitFile << "Patient admitted to Observation Unit at: " << std::ctime(&ct) << "\n";
                                std::cout << "Patient admitted to Observation Unit at: " << std::ctime(&ct) << "\n";
                            }

                        }
                        // Check for Expired Patient
                        if (p.isExpired()) {
                            // If the patient is expired, send them to the morgue
                            HospitalMorgue morgue;  //creating morgue object to class
                            morgue.setProcessed(true);
                            morgue.setProcessingTime(ct);
                            p.setHospitalMorgue(morgue);
                            morgueFile << "Patient processed at morgue at: " << std::ctime(&ct) << "\n";
                            std::cout << "Patient processed at morgue at: " << std::ctime(&ct) << "\n";






                            ptn.push_back(p);
                            break;
                        }
                        if (!OFB[i].getStatus()) {
                            OFB[i].setAssignment(true); // Assign Minor Procedure Bed
                            p.setTimeOfBedAssignment(ct);
                            p.setTypeOfBed("Overflow Bed");
                            admissionFile << "Patient admitted at: " << std::ctime(&ct) << "\n";
                            p.set_Lab_type("X_Ray");
                            for (int i = 0; i < 10; i++)

                                if (X_Ray_Labs[i].get_lab_status())
                                {
                                    p.set_test_type("X-Ray");
                                    laboratoryFile << "X-Ray tests being conducted for category 4 patient at: " << std::ctime(&ct) << "\n";
                                }
                                else
                                {
                                    laboratoryFile << "Labs full." << std::endl;
                                }
                        }
                        p.set_doctor_type("SeniorResidents");
                        for (int i = 0; i < 10; i++)
                        {
                            if (SeniorResidents->getStatus())
                            {
                                p.assign_treatment("Routine diagnostic test");
                                TreatmentFile << " Routine diagnostic test being conducted for category 4 patient at: " << std::ctime(&ct) << "\n";


                            }
                            else
                            {
                                TreatmentFile << "All Senior Doctors are busy." << std::endl;
                            }
                        }

                        for (int i = 0; i < 100; i++)
                        {
                            if (nurse->get_nurse_status())
                            {
                                p.assign_nurse(i);
                                NursingFile << "urse alloted to hanle patient in Category 4 at:" << std::ctime(&ct);
                            }
                            else
                            {
                                NursingFile << "All Nurses are busy." << std::endl;
                            }


                        }
                        for (int i = 0; i < 10; i++)
                        {
                            if (tp->get_precedure_status())
                            {
                                p.assign_treatment_procedure("Physical Therapy exercise");
                                ProcedureFile << "Treatment procedure being carried out on patient of CAT 4 at:" << std::ctime(&ct);
                            }
                            else
                            {
                                ProcedureFile << "Treatment procedure not available."; std::cout << std::endl;
                            }
                        }

                        // Discharge Logic: Home
                        if (p.getCategory() == 2 && p.getTypeOfBed() == "Overflow Bed" && !p.isExpired()) {
                            if (p.getTimeOfTreatment() > 0 && p.getTimeOfTreatment() - p.getTimeOfBedAssignment() > 3600) { // Assuming 1 hour of treatment
                                p.setDischarged(true);
                                p.setDischargeTime(ct);
                                homeFile << "Patient discharged to home at: " << std::ctime(&ct) << "\n";
                                std::cout << "Patient discharged to home at: " << std::ctime(&ct) << "\n";
                            }
                        }

                        // Transfer to Alternative Hospital
                        if (p.getCategory() == 2 && !p.getDischarged() && p.getTypeOfBed() == "Overflow Bed" && !p.isExpired()) {
                            if (p.getTimeOfTreatment() > 0 && p.getTimeOfTreatment() - p.getTimeOfBedAssignment() > 7200) { // 2 hours of treatment time
                                TransferToAlternativeHospital transfer; //creating transfer object to class 
                                transfer.setTransferred(true);
                                transfer.setTransferTime(ct);
                                p.setTransferToAltHosp(transfer);
                                transferFile << "Patient transferred to alternative hospital at: " << std::ctime(&ct) << "\n";
                                std::cout << "Patient transferred to alternative hospital at: " << std::ctime(&ct) << "\n";
                            }
                        }

                        // Observation Unit Admission
                        if (p.getCategory() == 2 && !p.getDischarged() && !p.getTransferred() && !p.isExpired()) {
                            if (p.getTimeOfTreatment() > 0 && p.getTimeOfTreatment() - p.getTimeOfBedAssignment() > 1800) { // 30 minutes of treatment
                                ObservationUnit observation; //creating observation object to class
                                observation.setAdmitted(true);
                                observation.setAdmissionTime(ct);
                                p.setObservationUnit(observation);
                                observationUnitFile << "Patient admitted to Observation Unit at: " << std::ctime(&ct) << "\n";
                                std::cout << "Patient admitted to Observation Unit at: " << std::ctime(&ct) << "\n";
                            }

                        }
                        // Check for Expired Patient
                        if (p.isExpired()) {
                            // If the patient is expired, send them to the morgue
                            HospitalMorgue morgue;  //creating morgue object to class
                            morgue.setProcessed(true);
                            morgue.setProcessingTime(ct);
                            p.setHospitalMorgue(morgue);
                            morgueFile << "Patient processed at morgue at: " << std::ctime(&ct) << "\n";
                            std::cout << "Patient processed at morgue at: " << std::ctime(&ct) << "\n";




                            ptn.push_back(p);
                            break;
                        }
                        // If no beds are available, queue the patient
                        p.setTimeOfBedAssignment(ct);
                        p.setTypeOfBed("Queued!");
                        ptn.push_back(p);
                        Q4.addPatient(p); // Add to the Minor Procedure queue
                        break;
                    }

                    else if (density >= 40) {
                        for (int i = 0; i < 10; i++)
                        {
                            p.setCategory(5); //  Category 5
                            if (!AB[i].getStatus())
                            {
                                AB[i].setAssignment(true); // Assign Acute Bed
                                p.setTimeOfBedAssignment(ct);
                                p.setTypeOfBed("Acute Bed");
                                admissionFile << "Patient admitted at: " << std::ctime(&ct) << "\n";
                                p.set_Lab_type("X_Ray");
                                for (int i = 0; i < 10; i++)
                                {
                                    if (X_Ray_Labs[i].get_lab_status())
                                    {
                                        p.set_test_type("X-Ray");
                                        laboratoryFile << "X-Ray tests being conducted for category 5 patient at: " << std::ctime(&ct) << "\n";
                                    }
                                    else
                                    {
                                        laboratoryFile << "Labs full." << std::endl;
                                    }
                                }
                                p.set_doctor_type("SeniorResidents");
                                for (int i = 0; i < 10; i++)
                                {
                                    if (SeniorResidents->getStatus())
                                    {
                                        p.assign_treatment("Scheduling non-emergency");
                                        TreatmentFile << " Scheduling non-emergency for category 5 patient at: " << std::ctime(&ct) << "\n";


                                    }
                                    else
                                    {
                                        TreatmentFile << "All Senior Doctors are busy." << std::endl;
                                    }
                                }
                                for (int i = 0; i < 100; i++)
                                {
                                    if (nurse->get_nurse_status())
                                    {
                                        p.assign_nurse(i);
                                        NursingFile << "urse alloted to hanle patient in Category 5 at:" << std::ctime(&ct);
                                    }
                                    else
                                    {
                                        NursingFile << "All Nurses are busy." << std::endl;
                                    }


                                }


                                for (int i = 0; i < 10; i++)
                                {
                                    if (tp->get_precedure_status())
                                    {
                                        p.assign_treatment_procedure("Bandage");
                                        ProcedureFile << "Treatment procedure being carried out on patient of CAT 4 at:" << std::ctime(&ct);
                                    }
                                    else
                                    {
                                        ProcedureFile << "Treatment procedure not available."; std::cout << std::endl;
                                    }
                                }

                                // Discharge Logic: Home
                                if (p.getCategory() == 2 && p.getTypeOfBed() == "Acute Bed" && !p.isExpired()) {
                                    if (p.getTimeOfTreatment() > 0 && p.getTimeOfTreatment() - p.getTimeOfBedAssignment() > 3600) { // Assuming 1 hour of treatment
                                        p.setDischarged(true);
                                        p.setDischargeTime(ct);
                                        homeFile << "Patient discharged to home at: " << std::ctime(&ct) << "\n";
                                        std::cout << "Patient discharged to home at: " << std::ctime(&ct) << "\n";
                                    }
                                }

                                // Transfer to Alternative Hospital
                                if (p.getCategory() == 2 && !p.getDischarged() && p.getTypeOfBed() == "Acute Bed" && !p.isExpired()) {
                                    if (p.getTimeOfTreatment() > 0 && p.getTimeOfTreatment() - p.getTimeOfBedAssignment() > 7200) { // 2 hours of treatment time
                                        TransferToAlternativeHospital transfer; //creating transfer object to class 
                                        transfer.setTransferred(true);
                                        transfer.setTransferTime(ct);
                                        p.setTransferToAltHosp(transfer);
                                        transferFile << "Patient transferred to alternative hospital at: " << std::ctime(&ct) << "\n";
                                        std::cout << "Patient transferred to alternative hospital at: " << std::ctime(&ct) << "\n";
                                    }
                                }

                                // Observation Unit Admission
                                if (p.getCategory() == 2 && !p.getDischarged() && !p.getTransferred() && !p.isExpired()) {
                                    if (p.getTimeOfTreatment() > 0 && p.getTimeOfTreatment() - p.getTimeOfBedAssignment() > 1800) { // 30 minutes of treatment
                                        ObservationUnit observation; //creating observation object to class
                                        observation.setAdmitted(true);
                                        observation.setAdmissionTime(ct);
                                        p.setObservationUnit(observation);
                                        observationUnitFile << "Patient admitted to Observation Unit at: " << std::ctime(&ct) << "\n";
                                        std::cout << "Patient admitted to Observation Unit at: " << std::ctime(&ct) << "\n";
                                    }

                                }
                                // Check for Expired Patient
                                if (p.isExpired()) {
                                    // If the patient is expired, send them to the morgue
                                    HospitalMorgue morgue;  //creating morgue object to class
                                    morgue.setProcessed(true);
                                    morgue.setProcessingTime(ct);
                                    p.setHospitalMorgue(morgue);
                                    morgueFile << "Patient processed at morgue at: " << std::ctime(&ct) << "\n";
                                    std::cout << "Patient processed at morgue at: " << std::ctime(&ct) << "\n";



                                    ptn.push_back(p);
                                    break;
                                }

                                if (!SB[i].getStatus()) {
                                    SB[i].setAssignment(true); // Assign Subacute Bed
                                    p.setTimeOfBedAssignment(ct);
                                    p.setTypeOfBed("Subacute Bed");
                                    admissionFile << "Patient admitted at: " << std::ctime(&ct) << "\n";
                                    p.set_Lab_type("X_Ray");
                                    for (int i = 0; i < 10; i++)
                                    {
                                        if (X_Ray_Labs[i].get_lab_status())
                                        {
                                            p.set_test_type("X_Ray");
                                            laboratoryFile << "X_Ray tests being conducted for category 5 patient at: " << std::ctime(&ct) << "\n";
                                        }
                                        else
                                        {
                                            laboratoryFile << "Labs full." << std::endl;
                                        }
                                    }
                                    p.set_doctor_type("SeniorResidents");
                                    for (int i = 0; i < 10; i++)
                                    {
                                        if (SeniorResidents->getStatus())
                                        {
                                            p.assign_treatment("Scheduling non-emergency");
                                            TreatmentFile << "Scheduling non-emergency for category 1 patient at: " << std::ctime(&ct) << "\n";


                                        }
                                        else
                                        {
                                            TreatmentFile << "All Senior Doctors are busy." << std::endl;
                                        }
                                    }
                                    for (int i = 0; i < 100; i++)
                                    {
                                        if (nurse->get_nurse_status())
                                        {
                                            p.assign_nurse(i);
                                            NursingFile << "Nurse alloted to hanle patient in Category 5 at:" << std::ctime(&ct);
                                        }
                                        else
                                        {
                                            NursingFile << "All Nurses are busy." << std::endl;
                                        }


                                    }

                                    for (int i = 0; i < 10; i++)
                                    {
                                        if (tp->get_precedure_status())
                                        {
                                            p.assign_treatment_procedure("Bandage");
                                            ProcedureFile << "Treatment procedure being carried out on patient of CAT 4 at:" << std::ctime(&ct);
                                        }
                                        else
                                        {
                                            ProcedureFile << "Treatment procedure not available."; std::cout << std::endl;
                                        }
                                    }

                                    // Discharge Logic: Home
                                    if (p.getCategory() == 2 && p.getTypeOfBed() == "Subacute Bed" && !p.isExpired()) {
                                        if (p.getTimeOfTreatment() > 0 && p.getTimeOfTreatment() - p.getTimeOfBedAssignment() > 3600) { // Assuming 1 hour of treatment
                                            p.setDischarged(true);
                                            p.setDischargeTime(ct);
                                            homeFile << "Patient discharged to home at: " << std::ctime(&ct) << "\n";
                                            std::cout << "Patient discharged to home at: " << std::ctime(&ct) << "\n";
                                        }
                                    }

                                    // Transfer to Alternative Hospital
                                    if (p.getCategory() == 2 && !p.getDischarged() && p.getTypeOfBed() == "Subacute Bed" && !p.isExpired()) {
                                        if (p.getTimeOfTreatment() > 0 && p.getTimeOfTreatment() - p.getTimeOfBedAssignment() > 7200) { // 2 hours of treatment time
                                            TransferToAlternativeHospital transfer; //creating transfer object to class 
                                            transfer.setTransferred(true);
                                            transfer.setTransferTime(ct);
                                            p.setTransferToAltHosp(transfer);
                                            transferFile << "Patient transferred to alternative hospital at: " << std::ctime(&ct) << "\n";
                                            std::cout << "Patient transferred to alternative hospital at: " << std::ctime(&ct) << "\n";
                                        }
                                    }

                                    // Observation Unit Admission
                                    if (p.getCategory() == 2 && !p.getDischarged() && !p.getTransferred() && !p.isExpired()) {
                                        if (p.getTimeOfTreatment() > 0 && p.getTimeOfTreatment() - p.getTimeOfBedAssignment() > 1800) { // 30 minutes of treatment
                                            ObservationUnit observation; //creating observation object to class
                                            observation.setAdmitted(true);
                                            observation.setAdmissionTime(ct);
                                            p.setObservationUnit(observation);
                                            observationUnitFile << "Patient admitted to Observation Unit at: " << std::ctime(&ct) << "\n";
                                            std::cout << "Patient admitted to Observation Unit at: " << std::ctime(&ct) << "\n";
                                        }

                                    }
                                    // Check for Expired Patient
                                    if (p.isExpired()) {
                                        // If the patient is expired, send them to the morgue
                                        HospitalMorgue morgue;  //creating morgue object to class
                                        morgue.setProcessed(true);
                                        morgue.setProcessingTime(ct);
                                        p.setHospitalMorgue(morgue);
                                        morgueFile << "Patient processed at morgue at: " << std::ctime(&ct) << "\n";
                                        std::cout << "Patient processed at morgue at: " << std::ctime(&ct) << "\n";



                                        ptn.push_back(p);
                                        break;
                                    }

                                    if (!MOPB[i].getStatus()) {
                                        MOPB[i].setAssignment(true); // Assign Minor Procedure Bed
                                        p.setTimeOfBedAssignment(ct);
                                        p.setTypeOfBed("Minor Procedure Bed");
                                        admissionFile << "Patient admitted at: " << std::ctime(&ct) << "\n";
                                        p.set_Lab_type("X_Ray");
                                        for (int i = 0; i < 10; i++)
                                        {
                                            if (X_Ray_Labs[i].get_lab_status())
                                            {
                                                p.set_test_type("X_Ray");
                                                laboratoryFile << "MRI tests being conducted for category 5 patient at: " << std::ctime(&ct) << "\n";
                                            }
                                            else
                                            {
                                                laboratoryFile << "Labs full." << std::endl;
                                            }
                                        }
                                        p.set_doctor_type("SeniorResidents");
                                        for (int i = 0; i < 10; i++)
                                        {
                                            if (SeniorResidents->getStatus())
                                            {
                                                p.assign_treatment("Scheduling non-emergency");
                                                TreatmentFile << " Scheduling non-emergency for category 5 patient at: " << std::ctime(&ct) << "\n";


                                            }
                                            else
                                            {
                                                TreatmentFile << "All Senior Doctors are busy." << std::endl;
                                            }
                                        }

                                        for (int i = 0; i < 100; i++)
                                        {
                                            if (nurse->get_nurse_status())
                                            {
                                                p.assign_nurse(i);
                                                for (int i = 0; i < 100; i++)
                                                {
                                                    if (nurse->get_nurse_status())
                                                    {
                                                        p.assign_nurse(i);
                                                        NursingFile << "Nurse alloted to hanle patient in Category 5 at:" << std::ctime(&ct);
                                                    }
                                                    else
                                                    {
                                                        NursingFile << "All Nurses are busy." << std::endl;
                                                    }


                                                }

                                            }


                                            for (int i = 0; i < 10; i++)
                                            {
                                                if (tp->get_precedure_status())
                                                {
                                                    p.assign_treatment_procedure("Bandage");
                                                    ProcedureFile << "Treatment procedure being carried out on patient of CAT 5 at:" << std::ctime(&ct);
                                                }
                                                else
                                                {
                                                    ProcedureFile << "Treatment procedure not available."; std::cout << std::endl;
                                                }
                                            }


                                        }

                                        // Discharge Logic: Home
                                        if (p.getCategory() == 2 && p.getTypeOfBed() == "Minor Procedure Bed" && !p.isExpired()) {
                                            if (p.getTimeOfTreatment() > 0 && p.getTimeOfTreatment() - p.getTimeOfBedAssignment() > 3600) { // Assuming 1 hour of treatment
                                                p.setDischarged(true);
                                                p.setDischargeTime(ct);
                                                homeFile << "Patient discharged to home at: " << std::ctime(&ct) << "\n";
                                                std::cout << "Patient discharged to home at: " << std::ctime(&ct) << "\n";
                                            }
                                        }

                                        // Transfer to Alternative Hospital
                                        if (p.getCategory() == 2 && !p.getDischarged() && p.getTypeOfBed() == "Minor Procedure Bed" && !p.isExpired()) {
                                            if (p.getTimeOfTreatment() > 0 && p.getTimeOfTreatment() - p.getTimeOfBedAssignment() > 7200) { // 2 hours of treatment time
                                                TransferToAlternativeHospital transfer; //creating transfer object to class 
                                                transfer.setTransferred(true);
                                                transfer.setTransferTime(ct);
                                                p.setTransferToAltHosp(transfer);
                                                transferFile << "Patient transferred to alternative hospital at: " << std::ctime(&ct) << "\n";
                                                std::cout << "Patient transferred to alternative hospital at: " << std::ctime(&ct) << "\n";
                                            }
                                        }

                                        // Observation Unit Admission
                                        if (p.getCategory() == 2 && !p.getDischarged() && !p.getTransferred() && !p.isExpired()) {
                                            if (p.getTimeOfTreatment() > 0 && p.getTimeOfTreatment() - p.getTimeOfBedAssignment() > 1800) { // 30 minutes of treatment
                                                ObservationUnit observation; //creating observation object to class
                                                observation.setAdmitted(true);
                                                observation.setAdmissionTime(ct);
                                                p.setObservationUnit(observation);
                                                observationUnitFile << "Patient admitted to Observation Unit at: " << std::ctime(&ct) << "\n";
                                                std::cout << "Patient admitted to Observation Unit at: " << std::ctime(&ct) << "\n";
                                            }

                                        }
                                        // Check for Expired Patient
                                        if (p.isExpired()) {
                                            // If the patient is expired, send them to the morgue
                                            HospitalMorgue morgue;  //creating morgue object to class
                                            morgue.setProcessed(true);
                                            morgue.setProcessingTime(ct);
                                            p.setHospitalMorgue(morgue);
                                            morgueFile << "Patient processed at morgue at: " << std::ctime(&ct) << "\n";
                                            std::cout << "Patient processed at morgue at: " << std::ctime(&ct) << "\n";





                                            ptn.push_back(p);
                                            break;
                                        }

                                        if (!OFB[i].getStatus()) {
                                            OFB[i].setAssignment(true); // Assign Minor Procedure Bed
                                            p.setTimeOfBedAssignment(ct);
                                            p.setTypeOfBed("Overflow Bed");
                                            admissionFile << "Patient admitted at: " << std::ctime(&ct) << "\n";
                                            p.set_Lab_type("X_Ray");
                                            for (int i = 0; i < 10; i++)

                                                if (X_Ray_Labs[i].get_lab_status())
                                                {
                                                    p.set_test_type("X-Ray");
                                                    laboratoryFile << "X-Ray tests being conducted for category 5 patient at: " << std::ctime(&ct) << "\n";
                                                }
                                                else
                                                {
                                                    laboratoryFile << "Labs full." << std::endl;
                                                }
                                        }
                                        p.set_doctor_type("SeniorResidents");
                                        for (int i = 0; i < 10; i++)
                                        {
                                            if (SeniorResidents->getStatus())
                                            {
                                                p.assign_treatment("Scheduling non-emergency");

                                                TreatmentFile << "Scheduling non-emergency for category 5 patient at: " << std::ctime(&ct) << "\n";
                                            }
                                            else
                                            {
                                                TreatmentFile << "All Senior Doctors are busy." << std::endl;
                                            }

                                        }
                                        for (int i = 0; i < 100; i++)
                                        {
                                            if (nurse->get_nurse_status())
                                            {
                                                p.assign_nurse(i);
                                                for (int i = 0; i < 100; i++)
                                                {
                                                    if (nurse->get_nurse_status())
                                                    {
                                                        p.assign_nurse(i);
                                                        NursingFile << "Nurse alloted to hanle patient in Category 5 at:" << std::ctime(&ct);
                                                    }
                                                    else
                                                    {
                                                        NursingFile << "All Nurses are busy." << std::endl;
                                                    }


                                                }

                                            }
                                            for (int i = 0; i < 10; i++)
                                            {
                                                if (tp->get_precedure_status())
                                                {
                                                    p.assign_treatment_procedure("Bandage");
                                                    ProcedureFile << "Treatment procedure being carried out on patient of CAT 5at:" << std::ctime(&ct);
                                                }
                                                else
                                                {
                                                    ProcedureFile << "Treatment procedure not available."; std::cout << std::endl;
                                                }
                                            }

                                        }

                                        // Discharge Logic: Home
                                        if (p.getCategory() == 2 && p.getTypeOfBed() == "Overflow Bed" && !p.isExpired()) {
                                            if (p.getTimeOfTreatment() > 0 && p.getTimeOfTreatment() - p.getTimeOfBedAssignment() > 3600) { // Assuming 1 hour of treatment
                                                p.setDischarged(true);
                                                p.setDischargeTime(ct);
                                                homeFile << "Patient discharged to home at: " << std::ctime(&ct) << "\n";
                                                std::cout << "Patient discharged to home at: " << std::ctime(&ct) << "\n";
                                            }
                                        }

                                        // Transfer to Alternative Hospital
                                        if (p.getCategory() == 2 && !p.getDischarged() && p.getTypeOfBed() == "Overflow Bed" && !p.isExpired()) {
                                            if (p.getTimeOfTreatment() > 0 && p.getTimeOfTreatment() - p.getTimeOfBedAssignment() > 7200) { // 2 hours of treatment time
                                                TransferToAlternativeHospital transfer; //creating transfer object to class 
                                                transfer.setTransferred(true);
                                                transfer.setTransferTime(ct);
                                                p.setTransferToAltHosp(transfer);
                                                transferFile << "Patient transferred to alternative hospital at: " << std::ctime(&ct) << "\n";
                                                std::cout << "Patient transferred to alternative hospital at: " << std::ctime(&ct) << "\n";
                                            }
                                        }

                                        // Observation Unit Admission
                                        if (p.getCategory() == 2 && !p.getDischarged() && !p.getTransferred() && !p.isExpired()) {
                                            if (p.getTimeOfTreatment() > 0 && p.getTimeOfTreatment() - p.getTimeOfBedAssignment() > 1800) { // 30 minutes of treatment
                                                ObservationUnit observation; //creating observation object to class
                                                observation.setAdmitted(true);
                                                observation.setAdmissionTime(ct);
                                                p.setObservationUnit(observation);
                                                observationUnitFile << "Patient admitted to Observation Unit at: " << std::ctime(&ct) << "\n";
                                                std::cout << "Patient admitted to Observation Unit at: " << std::ctime(&ct) << "\n";
                                            }

                                        }
                                        // Check for Expired Patient
                                        if (p.isExpired()) {
                                            // If the patient is expired, send them to the morgue
                                            HospitalMorgue morgue;  //creating morgue object to class
                                            morgue.setProcessed(true);
                                            morgue.setProcessingTime(ct);
                                            p.setHospitalMorgue(morgue);
                                            morgueFile << "Patient processed at morgue at: " << std::ctime(&ct) << "\n";
                                            std::cout << "Patient processed at morgue at: " << std::ctime(&ct) << "\n";


                                            ptn.push_back(p);
                                            break;
                                        }

                                        // Overflow category: Density >= 40
                                        p.setCategory(5);
                                        p.setTimeOfBedAssignment(ct);
                                        p.setTypeOfBed("Queued!");
                                        ptn.push_back(p);
                                        Q5.addPatient(p); // Add to the Overflow queue
                                    }


                                    current_start++;
                                }



                                admissionFile.close(); // Close the admission file
                                laboratoryFile.close(); //close lab file
                                TreatmentFile.close(); //cloase treatment file
                                NursingFile.close(); //cloas nursing file
                                ProcedureFile.close();//close procedure file
                                // Function to close all opened files
                                void closeAllFiles() {
                                    if (transferFile.is_open()) transferFile.close();
                                    if (observationFile.is_open()) observationFile.close();
                                    if (inpatientFile.is_open()) inpatientFile.close();
                                    if (homeFile.is_open()) homeFile.close();
                                    if (morgueFile.is_open()) morgueFile.close();
                                }


                                // Doctor allocation and deallocation should be handled outside the lambdas for persistence
                                int counter = 0;
                                std::ofstream dischareFile("discharge_file.txt", std::ios::app);
                                if (!dischareFile)
                                {
                                    std::cerr << "Failed to open discharge_file.txt";
                                    return;
                                }
                                // Doctor allocation, utilization, and deallocation
                                auto allocateDoctors = [&counter](Doctor* doctors, int max_doctors) {
                                    if (counter < max_doctors) {
                                        doctors[counter].setStatus(false);
                                        counter++;
                                    }
                                    else {
                                        std::cout << "All doctors are busy now!\n";
                                    }
                                    };



                                auto deallocateDoctors = [&counter](Doctor* doctors) {
                                    if (counter > 0) {
                                        doctors[counter - 1].setStatus(true);
                                        counter--;
                                    }
                                    };

                                current_start = 0;

                                while (current_start < 100)
                                {
                                    double pdt = 1000 * (PDDT(current_start));
                                    int pdt2 = static_cast<int>(pdt);
                                    current_start++;

                                    // Allocate doctors for each category
                                    allocateDoctors(Consultants, 10);
                                    allocateDoctors(Registrars, 10);
                                    allocateDoctors(SeniorResidents, 10);
                                    allocateDoctors(JuniorResidents, 10);
                                    allocateDoctors(Interns, 10);

                                    // Treat patients in different categories
                                    ct2 += static_cast<time_t>(pdt2);
                                    treatPatients(RB, Rbs, ct2, Consultants, cdoctor, pdt2, dischareFile); // Resuscitation Category
                                    treatPatients(AB, Abs, ct2, Registrars, rgsdoctor, pdt2, dischareFile); // Acute Category
                                    treatPatients(SB, Sbs, ct2, SeniorResidents, srdoctor, pdt2, dischareFile); // Subacute Category
                                    treatPatients(MOPB, Mbs, ct2, JuniorResidents, jrdoctor, pdt2, dischareFile); // Minor Procedure Category
                                    treatPatients(OFB, Mbs, ct2, Interns, idoctor, pdt2, dischareFile); // Overflow Category

                                    // Deallocate doctors after patient treatment
                                    deallocateDoctors(Consultants);
                                    deallocateDoctors(Registrars);
                                    deallocateDoctors(SeniorResidents);
                                    deallocateDoctors(JuniorResidents);
                                    deallocateDoctors(Interns);
                                }

                                std::cout << "All done\n";
                                system("pause");
                            }

                            int main()
                            {
                                ControlFlow();
                                return 0;
                            }