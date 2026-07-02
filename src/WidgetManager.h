#pragma once

// Pushes the current settings (position/scale/alpha/visibility) into every
// loaded widget movie. Call after settings change or on menu transitions.
void CheckInI();

// Safely toggle the visibility of a variable inside the vanilla HUD movie.
// Writes only when the value actually changes, and re-applies automatically
// if the HUD movie gets recreated (otherwise hidden vanilla elements such as
// the compass arrow/shout meter could silently reappear).
void SetHudVisible(RE::GFxMovieView* hud, const char* path, bool visible);
