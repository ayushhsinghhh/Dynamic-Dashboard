#pragma once

#include <msclr/marshal_cppstd.h>
#include <string>
#include <fstream>

namespace FinalDynadash {

    using namespace System;
    using namespace System::Windows::Forms;

    public ref class ColumnNamesForm : public System::Windows::Forms::Form
    {
    public:
        ColumnNamesForm(String^ graphType)
        {
            InitializeComponent();
            this->Text = "Input Column Names for " + graphType;
            this->graphType = graphType;
        }

    protected:
        ~ColumnNamesForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private: System::Windows::Forms::Label^ xAxisLabel;
    private: System::Windows::Forms::Label^ yAxisLabel;
    private: System::Windows::Forms::TextBox^ xAxisTextBox;
    private: System::Windows::Forms::TextBox^ yAxisTextBox;
    private: System::Windows::Forms::Button^ plotButton;
    private: String^ graphType;

#pragma region Windows Form Designer generated code
           void InitializeComponent(void)
           {
               this->xAxisLabel = (gcnew System::Windows::Forms::Label());
               this->yAxisLabel = (gcnew System::Windows::Forms::Label());
               this->xAxisTextBox = (gcnew System::Windows::Forms::TextBox());
               this->yAxisTextBox = (gcnew System::Windows::Forms::TextBox());
               this->plotButton = (gcnew System::Windows::Forms::Button());
               this->SuspendLayout();
               // 
               // xAxisLabel
               // 
               this->xAxisLabel->AutoSize = true;
               this->xAxisLabel->Location = System::Drawing::Point(50, 50);
               this->xAxisLabel->Name = L"xAxisLabel";
               this->xAxisLabel->Size = System::Drawing::Size(63, 17);
               this->xAxisLabel->TabIndex = 0;
               this->xAxisLabel->Text = L"X-Axis :";
               // 
               // yAxisLabel
               // 
               this->yAxisLabel->AutoSize = true;
               this->yAxisLabel->Location = System::Drawing::Point(50, 100);
               this->yAxisLabel->Name = L"yAxisLabel";
               this->yAxisLabel->Size = System::Drawing::Size(63, 17);
               this->yAxisLabel->TabIndex = 1;
               this->yAxisLabel->Text = L"Y-Axis :";
               // 
               // xAxisTextBox
               // 
               this->xAxisTextBox->Location = System::Drawing::Point(120, 50);
               this->xAxisTextBox->Name = L"xAxisTextBox";
               this->xAxisTextBox->Size = System::Drawing::Size(150, 22);
               this->xAxisTextBox->TabIndex = 2;
               // 
               // yAxisTextBox
               // 
               this->yAxisTextBox->Location = System::Drawing::Point(120, 100);
               this->yAxisTextBox->Name = L"yAxisTextBox";
               this->yAxisTextBox->Size = System::Drawing::Size(150, 22);
               this->yAxisTextBox->TabIndex = 3;
               // 
               // plotButton
               // 
               this->plotButton->Location = System::Drawing::Point(120, 150);
               this->plotButton->Name = L"plotButton";
               this->plotButton->Size = System::Drawing::Size(100, 30);
               this->plotButton->TabIndex = 4;
               this->plotButton->Text = L"Plot";
               this->plotButton->UseVisualStyleBackColor = true;
               this->plotButton->Click += gcnew System::EventHandler(this, &ColumnNamesForm::plotButton_Click);
               // 
               // ColumnNamesForm
               // 
               this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
               this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
               this->ClientSize = System::Drawing::Size(300, 200);
               this->Controls->Add(this->plotButton);
               this->Controls->Add(this->yAxisTextBox);
               this->Controls->Add(this->xAxisTextBox);
               this->Controls->Add(this->yAxisLabel);
               this->Controls->Add(this->xAxisLabel);
               this->Name = L"ColumnNamesForm";
               this->Text = L"Input Column Names";
               this->ResumeLayout(false);
               this->PerformLayout();

           }
#pragma endregion

    private: System::Void plotButton_Click(System::Object^ sender, System::EventArgs^ e) {
        // Get the entered column names from the textboxes
        String^ xAxisColumnName = xAxisTextBox->Text;
        String^ yAxisColumnName = yAxisTextBox->Text;

        // Convert System::String to std::string for use with Gnuplot
        msclr::interop::marshal_context context;
        std::string xColumnName = context.marshal_as<std::string>(xAxisColumnName);
        std::string yColumnName = context.marshal_as<std::string>(yAxisColumnName);

        // Generate a data file with dummy data for demonstration (Replace this with your actual data)
        std::ofstream dataFile("data.dat");
        dataFile << "1 10\n2 20\n3 30\n4 40\n5 50\n"; // Example data: x y
        dataFile.close();

        // Create Gnuplot process
        FILE* gnuplotPipe = _popen("gnuplot -persist", "w");

        if (gnuplotPipe) {
            fprintf(gnuplotPipe, "set title '%s'\n", context.marshal_as<std::string>(graphType).c_str());
            fprintf(gnuplotPipe, "plot 'data.dat' using 1:2 title '%s' with lines\n", xColumnName.c_str());

            fflush(gnuplotPipe); // Flush the pipe
            _pclose(gnuplotPipe); // Close the pipe
        }
        else {
            MessageBox::Show("Gnuplot not found or failed to open. Make sure Gnuplot is installed and added to system PATH.");
        }

        // Remove temporary data file
        remove("data.dat");
    }
    };
}
