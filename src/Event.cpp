#include "Event.hpp"

#include "Config.hpp"
#include "Errors.hpp"
#include "utils/Logger.hpp"

#include "Engine.hpp"
#include "utils/String.hpp"

std::string Event::ButtonName(uint button)
{
	switch (button)
	{
		case GLFW_MOUSE_BUTTON_1:
			return "Left button";
			break;
		case GLFW_MOUSE_BUTTON_3:
			return "Middle button";
			break;
		case GLFW_MOUSE_BUTTON_2:
			return "Right button";
			break;
		case GLFW_MOUSE_BUTTON_4:
			return "Extra button 1";
			break;
		case GLFW_MOUSE_BUTTON_5:
			return "Extra button 2";
			break;
		case GLFW_MOUSE_BUTTON_6:
			return "Extra button 3";
			break;
		case GLFW_MOUSE_BUTTON_7:
			return "Extra button 4";
			break;
		case GLFW_MOUSE_BUTTON_8:
			return "Extra button 5";
			break;
	}
	
	return GetErrorMessage(ERR_UNKNOWN);
}

std::string Event::KeyName(uint key)
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
		case GLFW_KEY_SPACE:         return "Space";           break;
		case GLFW_KEY_MINUS:         return "Minus";           break;
		case GLFW_KEY_EQUAL:         return "Equal";           break;
		case GLFW_KEY_LEFT_BRACKET:  return "Left bracket";    break;
		case GLFW_KEY_RIGHT_BRACKET: return "Right bracket";   break;
		case GLFW_KEY_BACKSLASH:     return "Backslash";       break;
		case GLFW_KEY_SEMICOLON:     return "Semicolon";       break;
		case GLFW_KEY_APOSTROPHE:    return "Apostrophe";      break;
		case GLFW_KEY_GRAVE_ACCENT:  return "Grave accent";    break;
		case GLFW_KEY_COMMA:         return "Comma";           break;
		case GLFW_KEY_PERIOD:        return "Period";          break;
		case GLFW_KEY_SLASH:         return "Slash";           break;
		case GLFW_KEY_WORLD_1:       return "World 1";         break;
		case GLFW_KEY_WORLD_2:       return "World 2";         break;
		case GLFW_KEY_ESCAPE:        return "Escape";          break;
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
		case GLFW_KEY_DOWN:          return "Down";            break;
		case GLFW_KEY_LEFT:          return "Left";            break;
		case GLFW_KEY_RIGHT:         return "Right";           break;
		case GLFW_KEY_LEFT_SHIFT:    return "Left shift";      break;
		case GLFW_KEY_RIGHT_SHIFT:   return "Right shift";     break;
		case GLFW_KEY_LEFT_CONTROL:  return "Left control";    break;
		case GLFW_KEY_RIGHT_CONTROL: return "Right control";   break;
		case GLFW_KEY_LEFT_ALT:      return "Left alt";        break;
		case GLFW_KEY_RIGHT_ALT:     return "Right alt";       break;
		case GLFW_KEY_TAB:           return "Tab";             break;
		case GLFW_KEY_ENTER:         return "Enter";           break;
		case GLFW_KEY_BACKSPACE:     return "Backspace";       break;
		case GLFW_KEY_INSERT:        return "Insert";          break;
		case GLFW_KEY_DELETE:        return "Delete";          break;
		case GLFW_KEY_PAGE_UP:       return "Page up";         break;
		case GLFW_KEY_PAGE_DOWN:     return "Page down";       break;
		case GLFW_KEY_HOME:          return "Home";            break;
		case GLFW_KEY_END:           return "End";             break;
		case GLFW_KEY_KP_0:          return "Keypad 0";        break;
		case GLFW_KEY_KP_1:          return "Keypad 1";        break;
		case GLFW_KEY_KP_2:          return "Keypad 2";        break;
		case GLFW_KEY_KP_3:          return "Keypad 3";        break;
		case GLFW_KEY_KP_4:          return "Keypad 4";        break;
		case GLFW_KEY_KP_5:          return "Keypad 5";        break;
		case GLFW_KEY_KP_6:          return "Keypad 6";        break;
		case GLFW_KEY_KP_7:          return "Keypad 7";        break;
		case GLFW_KEY_KP_8:          return "Keypad 8";        break;
		case GLFW_KEY_KP_9:          return "Keypad 9";        break;
		case GLFW_KEY_KP_DIVIDE:     return "Keypad divide";   break;
		case GLFW_KEY_KP_MULTIPLY:   return "Keypad multiply"; break;
		case GLFW_KEY_KP_SUBTRACT:   return "Keypad subtract"; break;
		case GLFW_KEY_KP_ADD:        return "Keypad add";      break;
		case GLFW_KEY_KP_DECIMAL:    return "Keypad decimal";  break;
		case GLFW_KEY_KP_EQUAL:      return "Keypad equal";    break;
		case GLFW_KEY_KP_ENTER:      return "Keypad enter";    break;
		case GLFW_KEY_PRINT_SCREEN:  return "Print screen";    break;
		case GLFW_KEY_NUM_LOCK:      return "Num lock";        break;
		case GLFW_KEY_CAPS_LOCK:     return "Caps lock";       break;
		case GLFW_KEY_SCROLL_LOCK:   return "Scroll lock";     break;
		case GLFW_KEY_PAUSE:         return "Pause";           break;
		case GLFW_KEY_LEFT_SUPER:    return "Left super";      break;
		case GLFW_KEY_RIGHT_SUPER:   return "Right super";     break;
		case GLFW_KEY_MENU:          return "Menu";            break;
		case GLFW_KEY_UNKNOWN:       return "Unknown";         break;
		default:                     return "";                break;
	}
}

void Event::HandleKeys(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (action == GLFW_RELEASE)
		Event::HandleKeyUp(window, key, scancode, mods);
	else
		Event::HandleKeyDown(window, key, scancode, mods);
}

void Event::HandleKeyUp(GLFWwindow* window, int key, int scancode, int mods)
{
	Log(LOG_TRACE) << "Key \'" << Event::KeyName(key) << "\' was released" << NEWLINE;
	
	switch (key)
	{
		case GLFW_KEY_ESCAPE:
			glfwSetWindowShouldClose(window, true);
			break;
	}
}

void Event::HandleKeyDown(GLFWwindow* window, int key, int scancode, int mods)
{
	Log(LOG_TRACE) << "Key \'" << Event::KeyName(key) << "\' was pressed" << NEWLINE;
}

void Event::HandleMouseButton(GLFWwindow* window, int button, int action, int mods)
{
	Log(LOG_TRACE) << "\'" << ButtonName(button) << "\' was " << ((action == GLFW_RELEASE) ? "released" : "pressed") << " at (" << Engine::Ref().GetMousePos().x << "," << Engine::Ref().GetMousePos().y << ")" << NEWLINE;
	
	if (action == GLFW_RELEASE)
	{
		
	}
	else
	{
		
	}
}

void Event::HandleMouseMove(GLFWwindow* window, double x, double y)
{
	//Log(LOG_TRACE) << "Mouse moved to (" << x << "," << y << ")" << NEWLINE; --- Way to much spam
	
	Engine::Ref().SetMousePos(x, y);
}

void Event::HandleMouseWheel(GLFWwindow* window, double xOff, double yOff)
{
	//Log(LOG_TRACE) << "Mouse wheel moved " << xOff << " left and " << yOff << " up" << NEWLINE; --- Way to much spam
}
