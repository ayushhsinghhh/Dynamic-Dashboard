#pragma once
namespace FinalDynadash{

    using namespace System;
    using namespace System::Windows::Forms;

    public ref class UploadForm : public System::Windows::Forms::Form
    {
    public:
        UploadForm(void)
        {
            InitializeComponent();
        }

    protected:
        ~UploadForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private: System::Windows::Forms::Button^ uploadButton;
    private: System::Windows::Forms::Button^ graphOptionsButton;

    private:
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->uploadButton = (gcnew System::Windows::Forms::Button());
            this->graphOptionsButton = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            // 
            // uploadButton
            // 
            this->uploadButton->Location = System::Drawing::Point(50, 50);
            this->uploadButton->Name = L"uploadButton";
            this->uploadButton->Size = System::Drawing::Size(150, 50);
            this->uploadButton->Text = L"Upload CSV File";
            this->uploadButton->UseVisualStyleBackColor = true;
            this->uploadButton->Click += gcnew System::EventHandler(this, &UploadForm::uploadButton_Click);
            // 
            // graphOptionsButton
            // 
            this->graphOptionsButton->Location = System::Drawing::Point(50, 110);
            this->graphOptionsButton->Name = L"graphOptionsButton";
            this->graphOptionsButton->Size = System::Drawing::Size(150, 50);
            this->graphOptionsButton->Text = L"Graph Options";
            this->graphOptionsButton->UseVisualStyleBackColor = true;
            this->graphOptionsButton->Click += gcnew System::EventHandler(this, &UploadForm::graphOptionsButton_Click);
            // 
            // UploadForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(300, 200);
            this->Controls->Add(this->graphOptionsButton);
            this->Controls->Add(this->uploadButton);
            this->Name = L"UploadForm";
            this->Text = L"Upload CSV File";
            this->ResumeLayout(false);
        }
#pragma endregion

    private: System::Void uploadButton_Click(System::Object^ sender, System::EventArgs^ e) {
        // Code to handle the file upload goes here
        OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
        openFileDialog->Filter = "CSV Files|*.csv";
        openFileDialog->Title = "Select a CSV File";

        if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
        {
            String^ filePath = openFileDialog->FileName;
            // Process the uploaded file (parse CSV data, etc.)
            MessageBox::Show("File " + filePath + " uploaded successfully!");
        }
    }

    private: System::Void graphOptionsButton_Click(System::Object^ sender, System::EventArgs^ e) {
        // Code to open a new form for graph options goes here
        // For example, create and display a new form for selecting graph types
        GraphTypeForm^ graphTypeForm = gcnew GraphTypeForm();
        graphTypeForm->ShowDialog();
    }
    };
}
