#include <vector>
#include <set>
#include <string>

namespace FinalDynaDash {

    // Assume this structure represents a user
    struct User {
        std::string username;
        std::string password;

        User(const std::string& uname, const std::string& pwd) : username(uname), password(pwd) {}
    };

    using namespace System;
    using namespace System::Windows::Forms;

    public ref class LoginSignupForm : public System::Windows::Forms::Form
    {
    public:
        LoginSignupForm(void)
        {
            InitializeComponent();
        }

    protected:
        ~LoginSignupForm()
        {
            // Cleanup: No cleanup needed in this example
        }

    private:
        System::Windows::Forms::TabControl^ tabControl;
        System::Windows::Forms::TabPage^ loginTabPage;
        System::Windows::Forms::TabPage^ signupTabPage;
        System::Windows::Forms::TextBox^ loginUsernameTextBox;
        System::Windows::Forms::TextBox^ loginPasswordTextBox;
        System::Windows::Forms::Button^ loginButton;
        System::Windows::Forms::TextBox^ signupUsernameTextBox;
        System::Windows::Forms::TextBox^ signupPasswordTextBox;
        System::Windows::Forms::Button^ signupButton;

        // Vector to store user information
        std::vector<User> users;

        System::Void InitializeComponent(void)
        {
            this->tabControl = (gcnew System::Windows::Forms::TabControl());
            this->loginTabPage = (gcnew System::Windows::Forms::TabPage());
            this->loginUsernameTextBox = (gcnew System::Windows::Forms::TextBox());
            this->loginPasswordTextBox = (gcnew System::Windows::Forms::TextBox());
            this->loginButton = (gcnew System::Windows::Forms::Button());
            this->signupTabPage = (gcnew System::Windows::Forms::TabPage());
            this->signupUsernameTextBox = (gcnew System::Windows::Forms::TextBox());
            this->signupPasswordTextBox = (gcnew System::Windows::Forms::TextBox());
            this->signupButton = (gcnew System::Windows::Forms::Button());

            // ... (your existing code for initializing components)

            // Add event handlers for loginButton_Click and signupButton_Click
            this->loginButton->Click += gcnew System::EventHandler(this, &LoginSignupForm::loginButton_Click);
            this->signupButton->Click += gcnew System::EventHandler(this, &LoginSignupForm::signupButton_Click);
        }

        System::Void loginButton_Click(System::Object^ sender, System::EventArgs^ e)
        {
            String^ enteredUsername = this->loginUsernameTextBox->Text;
            String^ enteredPassword = this->loginPasswordTextBox->Text;

            // Check if the entered username exists
            auto it = std::find_if(users.begin(), users.end(), [&](const User& user) {
                return user.username == msclr::interop::marshal_as<std::string>(enteredUsername);
                });

            if (it != users.end()) {
                // Check if the entered password matches
                if (it->password == msclr::interop::marshal_as<std::string>(enteredPassword)) {
                    MessageBox::Show("Login successful!");
                }
                else {
                    MessageBox::Show("Incorrect password. Please try again.");
                }
            }
            else {
                MessageBox::Show("Username not found. Please sign up.");
            }
        }

        System::Void signupButton_Click(System::Object^ sender, System::EventArgs^ e)
        {
            String^ newUsername = this->signupUsernameTextBox->Text;
            String^ newPassword = this->signupPasswordTextBox->Text;

            // Check if the username is already registered
            auto it = std::find_if(users.begin(), users.end(), [&](const User& user) {
                return user.username == msclr::interop::marshal_as<std::string>(newUsername);
                });

            if (it != users.end()) {
                MessageBox::Show("Username already exists. Please choose a different username.");
            }
            else {
                // Register the new user
                users.push_back(User(msclr::interop::marshal_as<std::string>(newUsername), msclr::interop::marshal_as<std::string>(newPassword)));
                MessageBox::Show("Signup successful!");
            }
        }
    };
}