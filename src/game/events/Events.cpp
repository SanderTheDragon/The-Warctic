#include "game/events/Events.hpp"

#include "Config.hpp"
#include "misc/Error.hpp"
#include "misc/Logger.hpp"

double Events::mouseX;
double Events::mouseY;

void Events::KeyHandle(GLFWwindow* window, int key, int scancode, int action, int mods)
{
#ifdef DEBUG
    const char* nameAction = "pressed";
    if (action == GLFW_RELEASE)
        nameAction = "released";
    
    const char* nameKey = KeyName(key);
    
    Log(LOG_DEBUG) << "Key " << nameKey << " has been " << nameAction << "\n";
#endif
    
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

void Events::MouseButtonHandle(GLFWwindow* window, int button, int action, int mods)
{
#ifdef DEBUG
    const char* nameButton = "Left";
    switch (button)
    {
    case GLFW_MOUSE_BUTTON_RIGHT:
        nameButton = "Right";
        break;
    case GLFW_MOUSE_BUTTON_MIDDLE:
        nameButton = "Middle";
        break;
    }
    
    const char* nameAction = "pressed";
    if (action == GLFW_RELEASE)
        nameAction = "released";
    
    Log(LOG_DEBUG) << nameButton << " mouse button has been " << nameAction << " at x:" << mouseX << ", y:" << mouseY << NEWLINE;
#endif
}

void Events::MouseMoveHandle(GLFWwindow* window, double x, double y)
{
    mouseX = x;
    mouseY = y;
}

const char* Events::KeyName(int key)
{
    switch (key)
    {
        case GLFW_KEY_A:             return "A";               break;
        case GLFW_KEY_B:             return "B";               break;
        case GLFW_KEY_C:             return "C";               break;
        case GLFW_KEY_D:             return "D";               break;
        case GLFW_KEY_E:             return "E";               break;
        case GLFW_KEY_F:             return "F";               break;
        case GLFW_KEY_G:             return "G";               break;
        case GLFW_KEY_H:             return "H";               break;
        case GLFW_KEY_I:             return "I";               break;
        case GLFW_KEY_J:             return "J";               break;
        case GLFW_KEY_K:             return "K";               break;
        case GLFW_KEY_L:             return "L";               break;
        case GLFW_KEY_M:             return "M";               break;
        case GLFW_KEY_N:             return "N";               break;
        case GLFW_KEY_O:             return "O";               break;
        case GLFW_KEY_P:             return "P";               break;
        case GLFW_KEY_Q:             return "Q";               break;
        case GLFW_KEY_R:             return "R";               break;
        case GLFW_KEY_S:             return "S";               break;
        case GLFW_KEY_T:             return "T";               break;
        case GLFW_KEY_U:             return "U";               break;
        case GLFW_KEY_V:             return "V";               break;
        case GLFW_KEY_W:             return "W";               break;
        case GLFW_KEY_X:             return "X";               break;
        case GLFW_KEY_Y:             return "Y";               break;
        case GLFW_KEY_Z:             return "Z";               break;
        case GLFW_KEY_1:             return "1";               break;
        case GLFW_KEY_2:             return "2";               break;
        case GLFW_KEY_3:             return "3";               break;
        case GLFW_KEY_4:             return "4";               break;
        case GLFW_KEY_5:             return "5";               break;
        case GLFW_KEY_6:             return "6";               break;
        case GLFW_KEY_7:             return "7";               break;
        case GLFW_KEY_8:             return "8";               break;
        case GLFW_KEY_9:             return "9";               break;
        case GLFW_KEY_0:             return "0";               break;
        case GLFW_KEY_SPACE:         return "SPACE";           break;
        case GLFW_KEY_MINUS:         return "MINUS";           break;
        case GLFW_KEY_EQUAL:         return "EQUAL";           break;
        case GLFW_KEY_LEFT_BRACKET:  return "LEFT BRACKET";    break;
        case GLFW_KEY_RIGHT_BRACKET: return "RIGHT BRACKET";   break;
        case GLFW_KEY_BACKSLASH:     return "BACKSLASH";       break;
        case GLFW_KEY_SEMICOLON:     return "SEMICOLON";       break;
        case GLFW_KEY_APOSTROPHE:    return "APOSTROPHE";      break;
        case GLFW_KEY_GRAVE_ACCENT:  return "GRAVE ACCENT";    break;
        case GLFW_KEY_COMMA:         return "COMMA";           break;
        case GLFW_KEY_PERIOD:        return "PERIOD";          break;
        case GLFW_KEY_SLASH:         return "SLASH";           break;
        case GLFW_KEY_WORLD_1:       return "WORLD 1";         break;
        case GLFW_KEY_WORLD_2:       return "WORLD 2";         break;
        case GLFW_KEY_ESCAPE:        return "ESCAPE";          break;
        case GLFW_KEY_F1:            return "F1";              break;
        case GLFW_KEY_F2:            return "F2";              break;
        case GLFW_KEY_F3:            return "F3";              break;
        case GLFW_KEY_F4:            return "F4";              break;
        case GLFW_KEY_F5:            return "F5";              break;
        case GLFW_KEY_F6:            return "F6";              break;
        case GLFW_KEY_F7:            return "F7";              break;
        case GLFW_KEY_F8:            return "F8";              break;
        case GLFW_KEY_F9:            return "F9";              break;
        case GLFW_KEY_F10:           return "F10";             break;
        case GLFW_KEY_F11:           return "F11";             break;
        case GLFW_KEY_F12:           return "F12";             break;
        case GLFW_KEY_F13:           return "F13";             break;
        case GLFW_KEY_F14:           return "F14";             break;
        case GLFW_KEY_F15:           return "F15";             break;
        case GLFW_KEY_F16:           return "F16";             break;
        case GLFW_KEY_F17:           return "F17";             break;
        case GLFW_KEY_F18:           return "F18";             break;
        case GLFW_KEY_F19:           return "F19";             break;
        case GLFW_KEY_F20:           return "F20";             break;
        case GLFW_KEY_F21:           return "F21";             break;
        case GLFW_KEY_F22:           return "F22";             break;
        case GLFW_KEY_F23:           return "F23";             break;
        case GLFW_KEY_F24:           return "F24";             break;
        case GLFW_KEY_F25:           return "F25";             break;
        case GLFW_KEY_UP:            return "UP";              break;
        case GLFW_KEY_DOWN:          return "DOWN";            break;
        case GLFW_KEY_LEFT:          return "LEFT";            break;
        case GLFW_KEY_RIGHT:         return "RIGHT";           break;
        case GLFW_KEY_LEFT_SHIFT:    return "LEFT SHIFT";      break;
        case GLFW_KEY_RIGHT_SHIFT:   return "RIGHT SHIFT";     break;
        case GLFW_KEY_LEFT_CONTROL:  return "LEFT CONTROL";    break;
        case GLFW_KEY_RIGHT_CONTROL: return "RIGHT CONTROL";   break;
        case GLFW_KEY_LEFT_ALT:      return "LEFT ALT";        break;
        case GLFW_KEY_RIGHT_ALT:     return "RIGHT ALT";       break;
        case GLFW_KEY_TAB:           return "TAB";             break;
        case GLFW_KEY_ENTER:         return "ENTER";           break;
        case GLFW_KEY_BACKSPACE:     return "BACKSPACE";       break;
        case GLFW_KEY_INSERT:        return "INSERT";          break;
        case GLFW_KEY_DELETE:        return "DELETE";          break;
        case GLFW_KEY_PAGE_UP:       return "PAGE UP";         break;
        case GLFW_KEY_PAGE_DOWN:     return "PAGE DOWN";       break;
        case GLFW_KEY_HOME:          return "HOME";            break;
        case GLFW_KEY_END:           return "END";             break;
        case GLFW_KEY_KP_0:          return "KEYPAD 0";        break;
        case GLFW_KEY_KP_1:          return "KEYPAD 1";        break;
        case GLFW_KEY_KP_2:          return "KEYPAD 2";        break;
        case GLFW_KEY_KP_3:          return "KEYPAD 3";        break;
        case GLFW_KEY_KP_4:          return "KEYPAD 4";        break;
        case GLFW_KEY_KP_5:          return "KEYPAD 5";        break;
        case GLFW_KEY_KP_6:          return "KEYPAD 6";        break;
        case GLFW_KEY_KP_7:          return "KEYPAD 7";        break;
        case GLFW_KEY_KP_8:          return "KEYPAD 8";        break;
        case GLFW_KEY_KP_9:          return "KEYPAD 9";        break;
        case GLFW_KEY_KP_DIVIDE:     return "KEYPAD DIVIDE";   break;
        case GLFW_KEY_KP_MULTIPLY:   return "KEYPAD MULTPLY";  break;
        case GLFW_KEY_KP_SUBTRACT:   return "KEYPAD SUBTRACT"; break;
        case GLFW_KEY_KP_ADD:        return "KEYPAD ADD";      break;
        case GLFW_KEY_KP_DECIMAL:    return "KEYPAD DECIMAL";  break;
        case GLFW_KEY_KP_EQUAL:      return "KEYPAD EQUAL";    break;
        case GLFW_KEY_KP_ENTER:      return "KEYPAD ENTER";    break;
        case GLFW_KEY_PRINT_SCREEN:  return "PRINT SCREEN";    break;
        case GLFW_KEY_NUM_LOCK:      return "NUM LOCK";        break;
        case GLFW_KEY_CAPS_LOCK:     return "CAPS LOCK";       break;
        case GLFW_KEY_SCROLL_LOCK:   return "SCROLL LOCK";     break;
        case GLFW_KEY_PAUSE:         return "PAUSE";           break;
        case GLFW_KEY_LEFT_SUPER:    return "LEFT SUPER";      break;
        case GLFW_KEY_RIGHT_SUPER:   return "RIGHT SUPER";     break;
        case GLFW_KEY_MENU:          return "MENU";            break;
        case GLFW_KEY_UNKNOWN:       return "UNKNOWN";         break;
        default:                     return "";                break;
    }
} 
