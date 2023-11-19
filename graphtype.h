#pragma once

#include "ColumnNamesForm.h"

namespace YourNamespace {

    using namespace System;
    using namespace System::Windows::Forms;

    public ref class GraphTypeForm : public System::Windows::Forms::Form
    {
    public:
        GraphTypeForm()
        {
            InitializeComponent();
        }

    protected:
        ~GraphTypeForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private: System::Windows::Forms::Button^ lineChartButton;
    private: System::Windows::Forms::Button^ barGraphButton;
    private: System::Windows::Forms::Button^ histogramButton;

#pragma region Windows Form Designer generated code
           void InitializeComponent(void)
           {
               this->lineChartButton = (gcnew System::Windows::Forms::Button());
               this->barGraphButton = (gcnew System::Windows::Forms::Button());
               this->histogramButton = (gcnew System::Windows::Forms::Button());
               this->SuspendLayout();
               // 
               // lineChartButton
               // 
               this->lineChartButton->Location = System::Drawing::Point(50, 50);
               this->lineChartButton->Name = L"lineChartButton";
               this->lineChartButton->Size = System::Drawing::Size(150, 50);
               this->lineChartButton->Text = L"Line Chart";
               this->lineChartButton->UseVisualStyleBackColor = true;
               this->lineChartButton->Click += gcnew System::EventHandler(this, &GraphTypeForm::lineChartButton_Click);
               // 
               // barGraphButton
               // 
               this->barGraphButton->Location = System::Drawing::Point(50, 110);
               this->barGraphButton->Name = L"barGraphButton";
               this->barGraphButton->Size = System::Drawing::Size(150, 50);
               this->barGraphButton->Text = L"Bar Graph";
               this->barGraphButton->UseVisualStyleBackColor = true;
               this->barGraphButton->Click += gcnew System::EventHandler(this, &GraphTypeForm::barGraphButton_Click);
               // 
               // histogramButton
               // 
               this->histogramButton->Location = System::Drawing::Point(50, 170);
               this->histogramButton->Name = L"histogramButton";
               this->histogramButton->Size = System::Drawing::Size(150, 50);
               this->histogramButton->Text = L"Histogram";
               this->histogramButton->UseVisualStyleBackColor = true;
               this->histogramButton->Click += gcnew System::EventHandler(this, &GraphTypeForm::histogramButton_Click);
               // 
               // GraphTypeForm
               // 
               this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
               this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
               this->ClientSize = System::Drawing::Size(250, 300);
               this->Controls->Add(this->histogramButton);
               this->Controls->Add(this->barGraphButton);
               this->Controls->Add(this->lineChartButton);
               this->Name = L"GraphTypeForm";
               this->Text = L"Select Graph Type";
               this->ResumeLayout(false);

           }
#pragma endregion

    private: System::Void lineChartButton_Click(System::Object^ sender, System::EventArgs^ e) {
        ColumnNamesForm^ columnNamesForm = gcnew ColumnNamesForm("Line Chart");
        columnNamesForm->ShowDialog();
    }

    private: System::Void barGraphButton_Click(System::Object^ sender, System::EventArgs^ e) {
        ColumnNamesForm^ columnNamesForm = gcnew ColumnNamesForm("Bar Graph");
        columnNamesForm->ShowDialog();
    }

    private: System::Void histogramButton_Click(System::Object^ sender, System::EventArgs^ e) {
        ColumnNamesForm^ columnNamesForm = gcnew ColumnNamesForm("Histogram");
        columnNamesForm->ShowDialog();
    }
    };
}
