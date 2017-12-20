#include "features.hpp"
    
unsigned char features::feature_flags = 
    features::support_unknown |
    features::color_support |
    features::ansi_cursor_support;

void features::full_feature_check() {
    std::cout << "\033[30mBlack\033[01m\t\tBright Black\033[00m" << std::endl;
    std::cout << "\033[31mRed\033[01m\t\tBright Red\033[00m" << std::endl;
    std::cout << "\033[32mGreen\033[01m\t\tBright Green\033[00m" << std::endl;
    std::cout << "\033[33mYellow/Orange\033[01m\tBright Yellow\033[00m" << std::endl;
    std::cout << "\033[34mBlue\033[01m\t\tBright Blue\033[00m" << std::endl;
    std::cout << "\033[35mMagenta/Purple\033[01m\tBright Magenta\033[00m" << std::endl;
    std::cout << "\033[36mAqua/Teal\033[01m\tBright Aqua\033[00m" << std::endl;
    std::cout << "\033[37mWhite/Gray\033[01m\tBright White\033[00m" << std::endl << std::endl;
   
    { 
        char response;
        while (true) {
            std::cout << "Is this text coloured? (Y/N) ";
            std::cin >> response;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (toupper(response) == 'Y') {
                feature_flags |= color_support;
                break;
            } else if (toupper(response) == 'N') {
                feature_flags &= ~color_support;
                break;
            } else {
                std::cerr << "Invalid input." << std::endl << std::endl;
            }
        }
    }

    std::cout << std::endl << std::endl;

    std::cout << "\033[02mFaint text\033[00m" << std::endl << std::endl;
    
    {
        char response;
        while (true) {
            std::cout << "Is this text faint? (Y/N) ";
            std::cin >> response;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (toupper(response) == 'Y') {
                feature_flags |= faint_color_support;
                break;
            } else if (toupper(response) == 'N') {
                feature_flags &= ~faint_color_support;
                break;
            } else {
                std::cerr << "Invalid input." << std::endl << std::endl;
            }
        }
    }

    std::cout << std::endl << std::endl;

    std::cout << "\033[03mItalic text\033[00m" << std::endl << std::endl;

    {
        char response;
        while (true) {
            std::cout << "Is this text italic? (Y/N) ";
            std::cin >> response;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (toupper(response) == 'Y') {
                feature_flags |= italic_support;
                break;
            } else if (toupper(response) == 'N') {
                feature_flags &= ~italic_support;
                break;
            } else {
                std::cerr << "Invalid input." << std::endl << std::endl;
            }
        }
    }

    std::cout << std::endl << std::endl;

    std::cout << "\033[05mBlinking text\033[00m" << std::endl << std::endl;

    {
        char response;
        while (true) {
            std::cout << "Is this text blinking? (Y/N) ";
            std::cin >> response;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (toupper(response) == 'Y') {
                feature_flags |= native_blink_support;
                break;
            } else if (toupper(response) == 'N') {
                feature_flags &= ~native_blink_support;
                break;
            } else {
                std::cerr << "Invalid input." << std::endl << std::endl;
            }
        }
    }

    std::cout << std::endl << std::endl;

    std::cout << "\033[38;5;196mBright Red (196)\033[00m" << std::endl;
    std::cout << "\033[38;5;46mBright Green (46)\033[00m" << std::endl;
    std::cout << "\033[38;5;21mBright Blue (21)\033[00m" << std::endl << std::endl;

    {
        char response;
        while (true) {
            std::cout << "Is this text coloured? (Y/N) ";
            std::cin >> response;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (toupper(response) == 'Y') {
                feature_flags |= xterm_256color_support;
                break;
            } else if (toupper(response) == 'N') {
                feature_flags &= ~xterm_256color_support;
                break;
            } else {
                std::cerr << "Invalid input." << std::endl << std::endl;
            }
        }
    }

    std::cout << std::endl << std::endl;

    std::cout << "\033[38;2;255;0;0mBright Red (255, 0, 0)\033[00m" << std::endl;
    std::cout << "\033[38;2;0;255;0mBright Green (0, 255, 0)\033[00m" << std::endl;
    std::cout << "\033[38;2;0;0;255mBright Blue (0, 0, 255)\033[00m" << std::endl << std::endl;

    {
        char response;
        while (true) {
            std::cout << "Is this text coloured? (Y/N) ";
            std::cin >> response;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (toupper(response) == 'Y') {
                feature_flags |= true_color_support;
                break;
            } else if (toupper(response) == 'N') {
                feature_flags &= ~true_color_support;
                break;
            } else {
                std::cerr << "Invalid input." << std::endl << std::endl;
            }
        }
    }

    std::cout << std::endl << std::endl;
    
    std::cout << "no\033[D\033[Dyes" << std::endl << std::endl;

    {
        char response;
        while (true) {
            std::cout << "Is the text displayed above 'yes'? (Y/N) ";
            std::cin >> response;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (toupper(response) == 'Y') {
                feature_flags |= ansi_cursor_support;
                break;
            } else if (toupper(response) == 'N') {
                feature_flags &= ~ansi_cursor_support;
                break;
            } else {
                std::cerr << "Invalid input." << std::endl << std::endl;
            }
        }
    }

    feature_flags &= ~support_unknown;
}

void features::save() {
    std::ofstream features_file;
    features_file.open("features.txt", std::ios::trunc);
    
    if (features_file.is_open()) {
        features_file << "color_support " << (has_color_support() ? "yes" : "no") << "\n";
        features_file << "faint_color_support " << (has_faint_color_support() ? "yes" : "no") << "\n";
        features_file << "italic_support " << (has_italic_support() ? "yes" : "no") << "\n";
        features_file << "native_blink_support " << (has_native_blink_support() ? "yes" : "no") << "\n";
        features_file << "xterm_256color_support " << (has_xterm_256color_support() ? "yes" : "no") << "\n";
        features_file << "true_color_support " << (has_true_color_support() ? "yes" : "no") << "\n";
        features_file << "ansi_cursor_support " << (has_ansi_cursor_support() ? "yes" : "no") << "\n";
    }
    
    features_file.close();
}

void features::load() {
    std::ifstream features_file;
    features_file.open("features.txt");
    
    if (features_file.is_open()) {
        std::string flag, value;
        while (std::getline(features_file, flag, ' ')) {
            std::getline(features_file, value, '\n');
            if (flag == "color_support") {
                if (value == "yes") {
                    feature_flags |= color_support;
                } else if (value == "no") {
                    feature_flags &= ~color_support;
                }
            } else if (flag == "faint_color_support") {
                if (value == "yes") {
                    feature_flags |= faint_color_support;
                } else if (value == "no") {
                    feature_flags &= ~faint_color_support;
                }
            } else if (flag == "italic_support") {
                if (value == "yes") {
                    feature_flags |= italic_support;
                } else if (value == "no") { 
                    feature_flags &= ~italic_support;
                }
            } else if (flag == "native_blink_support") {
                if (value == "yes") {
                    feature_flags |= native_blink_support;
                } else if (value == "no") {
                    feature_flags &= ~native_blink_support;
                }
            } else if (flag == "xterm_256color_support") {
                if (value == "yes") {
                    feature_flags |= xterm_256color_support;
                } else if (value == "no") {
                    feature_flags &= ~xterm_256color_support;
                }
            } else if (flag == "true_color_support") {
                if (value == "yes") {
                    feature_flags |= true_color_support;
                } else if (value == "no") {
                    feature_flags &= ~true_color_support;
                }
            } else if (flag == "ansi_cursor_support") {
                if (value == "yes") {
                    feature_flags |= ansi_cursor_support;
                } else if (value == "no") {
                    feature_flags &= ~ansi_cursor_support;
                }
            }
        }
        feature_flags &= ~support_unknown;
    }

    features_file.close();
}


bool features::has_color_support() {
    return feature_flags & color_support;
}

bool features::has_faint_color_support() {
    return feature_flags & faint_color_support;
}

bool features::has_italic_support() {
    return feature_flags & italic_support;
}

bool features::has_native_blink_support() {
    return feature_flags & native_blink_support;
}

bool features::has_xterm_256color_support() {
    return feature_flags & xterm_256color_support;
}

bool features::has_true_color_support() {
    return feature_flags & true_color_support;
}

bool features::has_ansi_cursor_support() {
    return feature_flags & ansi_cursor_support;
}


bool features::is_support_unknown() {
    return feature_flags & support_unknown;
}

