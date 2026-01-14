#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_ID_LENGTH 10

// Structure for student billing record
typedef struct {
    char id[MAX_ID_LENGTH];
    char name[MAX_NAME_LENGTH];
    float tuition_fee;
    float hostel_fee;
    float library_fee;
    float lab_fee;
    float total_amount;
    float amount_paid;
    float balance;
} Student;

Student students[MAX_STUDENTS];
int student_count = 0;

// Function prototypes
void display_menu();
void add_student();
void calculate_bill(int index);
void display_all_students();
void search_student();
void update_payment();
void delete_student();
void save_to_file();
void load_from_file();
int find_student_by_id(char id[]);
void clear_input_buffer();

int main() {
    int choice;
    
    // Load existing data from file
    load_from_file();
    
    printf("========================================\n");
    printf("   STUDENT BILLING SYSTEM\n");
    printf("========================================\n");
    
    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clear_input_buffer();
        
        switch(choice) {
            case 1:
                add_student();
                break;
            case 2:
                display_all_students();
                break;
            case 3:
                search_student();
                break;
            case 4:
                update_payment();
                break;
            case 5:
                delete_student();
                break;
            case 6:
                save_to_file();
                break;
            case 7:
                printf("Loading data from file...\n");
                load_from_file();
                break;
            case 8:
                printf("Exiting system. Goodbye!\n");
                save_to_file(); // Auto-save on exit
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
        
        printf("\nPress Enter to continue...");
        getchar();
        
    } while(choice != 8);
    
    return 0;
}

void display_menu() {
    printf("\n============ MAIN MENU ============\n");
    printf("1. Add New Student\n");
    printf("2. Display All Students\n");
    printf("3. Search Student\n");
    printf("4. Update Payment\n");
    printf("5. Delete Student Record\n");
    printf("6. Save Data to File\n");
    printf("7. Load Data from File\n");
    printf("8. Exit\n");
    printf("===================================\n");
}

void add_student() {
    if(student_count >= MAX_STUDENTS) {
        printf("Database is full! Cannot add more students.\n");
        return;
    }
    
    Student new_student;
    
    printf("\n--- Add New Student ---\n");
    
    // Get student ID
    printf("Enter Student ID: ");
    fgets(new_student.id, MAX_ID_LENGTH, stdin);
    new_student.id[strcspn(new_student.id, "\n")] = 0;
    
    // Check if ID already exists
    if(find_student_by_id(new_student.id) != -1) {
        printf("Error: Student ID already exists!\n");
        return;
    }
    
    // Get student name
    printf("Enter Student Name: ");
    fgets(new_student.name, MAX_NAME_LENGTH, stdin);
    new_student.name[strcspn(new_student.name, "\n")] = 0;
    
    // Get fee details
    printf("\nEnter Fee Details:\n");
    printf("Tuition Fee: ");
    scanf("%f", &new_student.tuition_fee);
    printf("Hostel Fee: ");
    scanf("%f", &new_student.hostel_fee);
    printf("Library Fee: ");
    scanf("%f", &new_student.library_fee);
    printf("Lab Fee: ");
    scanf("%f", &new_student.lab_fee);
    
    // Get payment
    printf("Amount Paid: ");
    scanf("%f", &new_student.amount_paid);
    
    clear_input_buffer();
    
    // Calculate total and balance
    calculate_bill(student_count);
    students[student_count] = new_student;
    calculate_bill(student_count);
    
    student_count++;
    printf("\nStudent added successfully!\n");
}

void calculate_bill(int index) {
    students[index].total_amount = students[index].tuition_fee + 
                                   students[index].hostel_fee + 
                                   students[index].library_fee + 
                                   students[index].lab_fee;
    
    students[index].balance = students[index].total_amount - 
                             students[index].amount_paid;
}

void display_all_students() {
    if(student_count == 0) {
        printf("\nNo student records found!\n");
        return;
    }
    
    printf("\n==============================================================");
    printf("========================================\n");
    printf("%-10s %-20s %-10s %-10s %-10s %-10s %-12s %-10s %-10s\n", 
           "ID", "Name", "Tuition", "Hostel", "Library", "Lab", 
           "Total", "Paid", "Balance");
    printf("==============================================================");
    printf("========================================\n");
    
    float total_collected = 0;
    float total_pending = 0;
    
    for(int i = 0; i < student_count; i++) {
        printf("%-10s %-20s %-10.2f %-10.2f %-10.2f %-10.2f %-12.2f %-10.2f %-10.2f\n",
               students[i].id,
               students[i].name,
               students[i].tuition_fee,
               students[i].hostel_fee,
               students[i].library_fee,
               students[i].lab_fee,
               students[i].total_amount,
               students[i].amount_paid,
               students[i].balance);
        
        total_collected += students[i].amount_paid;
        total_pending += students[i].balance;
    }
    
    printf("=================================================================");
    printf("=======================================\n");
    printf("SUMMARY: Total Collected: ₹%.2f | Total Pending: ₹%.2f\n", 
           total_collected, total_pending);
}

void search_student() {
    if(student_count == 0) {
        printf("\nNo student records found!\n");
        return;
    }
    
    char search_id[MAX_ID_LENGTH];
    printf("\nEnter Student ID to search: ");
    fgets(search_id, MAX_ID_LENGTH, stdin);
    search_id[strcspn(search_id, "\n")] = 0;
    
    int index = find_student_by_id(search_id);
    
    if(index == -1) {
        printf("Student not found!\n");
        return;
    }
    
    printf("\n========== STUDENT BILL DETAILS ==========\n");
    printf("Student ID: %s\n", students[index].id);
    printf("Name: %s\n", students[index].name);
    printf("------------------------------------------\n");
    printf("FEES BREAKDOWN:\n");
    printf("  Tuition Fee: ₹%.2f\n", students[index].tuition_fee);
    printf("  Hostel Fee: ₹%.2f\n", students[index].hostel_fee);
    printf("  Library Fee: ₹%.2f\n", students[index].library_fee);
    printf("  Lab Fee: ₹%.2f\n", students[index].lab_fee);
    printf("------------------------------------------\n");
    printf("Total Amount: ₹%.2f\n", students[index].total_amount);
    printf("Amount Paid: ₹%.2f\n", students[index].amount_paid);
    printf("Balance Due: ₹%.2f\n", students[index].balance);
    printf("==========================================\n");
    
    if(students[index].balance > 0) {
        printf("Status: Payment Pending\n");
    } else if(students[index].balance < 0) {
        printf("Status: Overpaid (Refund: ₹%.2f)\n", -students[index].balance);
    } else {
        printf("Status: Fully Paid\n");
    }
}

void update_payment() {
    if(student_count == 0) {
        printf("\nNo student records found!\n");
        return;
    }
    
    char student_id[MAX_ID_LENGTH];
    printf("\nEnter Student ID to update payment: ");
    fgets(student_id, MAX_ID_LENGTH, stdin);
    student_id[strcspn(student_id, "\n")] = 0;
    
    int index = find_student_by_id(student_id);
    
    if(index == -1) {
        printf("Student not found!\n");
        return;
    }
    
    printf("\nCurrent payment: ₹%.2f\n", students[index].amount_paid);
    printf("Current balance: ₹%.2f\n", students[index].balance);
    
    float additional_payment;
    printf("Enter additional payment amount: ");
    scanf("%f", &additional_payment);
    clear_input_buffer();
    
    if(additional_payment < 0) {
        printf("Invalid amount! Payment cannot be negative.\n");
        return;
    }
    
    students[index].amount_paid += additional_payment;
    calculate_bill(index);
    
    printf("\nPayment updated successfully!\n");
    printf("New total paid: ₹%.2f\n", students[index].amount_paid);
    printf("New balance: ₹%.2f\n", students[index].balance);
}

void delete_student() {
    if(student_count == 0) {
        printf("\nNo student records found!\n");
        return;
    }
    
    char student_id[MAX_ID_LENGTH];
    printf("\nEnter Student ID to delete: ");
    fgets(student_id, MAX_ID_LENGTH, stdin);
    student_id[strcspn(student_id, "\n")] = 0;
    
    int index = find_student_by_id(student_id);
    
    if(index == -1) {
        printf("Student not found!\n");
        return;
    }
    
    printf("Are you sure you want to delete %s (ID: %s)? (y/n): ", 
           students[index].name, students[index].id);
    
    char confirm;
    scanf("%c", &confirm);
    clear_input_buffer();
    
    if(tolower(confirm) == 'y') {
        // Shift all elements after index to the left
        for(int i = index; i < student_count - 1; i++) {
            students[i] = students[i + 1];
        }
        
        student_count--;
        printf("Student record deleted successfully!\n");
    } else {
        printf("Deletion cancelled.\n");
    }
}

void save_to_file() {
    FILE *file = fopen("student_billing.dat", "wb");
    
    if(file == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }
    
    // Write student count
    fwrite(&student_count, sizeof(int), 1, file);
    
    // Write all student records
    fwrite(students, sizeof(Student), student_count, file);
    
    fclose(file);
    printf("Data saved to file successfully! (%d records)\n", student_count);
}

void load_from_file() {
    FILE *file = fopen("student_billing.dat", "rb");
    
    if(file == NULL) {
        printf("No previous data found. Starting with empty database.\n");
        return;
    }
    
    // Read student count
    fread(&student_count, sizeof(int), 1, file);
    
    // Read all student records
    fread(students, sizeof(Student), student_count, file);
    
    fclose(file);
    printf("Data loaded successfully! (%d records)\n", student_count);
}

int find_student_by_id(char id[]) {
    for(int i = 0; i < student_count; i++) {
        if(strcmp(students[i].id, id) == 0) {
            return i;
        }
    }
    return -1;
}

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

//gcc student_billing.c -o billing_system
//./billing_system