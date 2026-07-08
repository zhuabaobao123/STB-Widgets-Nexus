#pragma once

// Pushes the current settings (position/scale/alpha/visibility) into every
// loaded widget movie. Call after settings change or on menu transitions.
void CheckInI();

// Set the visibility of a variable inside the vanilla HUD movie. Writes
// unconditionally (no caching) so it stays correct even when another HUD mod
// changes the same Scaleform variable behind our back.
void SetHudVisible(RE::GFxMovieView* hud, const char* path, bool visible);
