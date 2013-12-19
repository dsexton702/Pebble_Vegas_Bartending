#include "pebble.h"
#include "pebble_fonts.h"


static Window *window;
static TextLayer *text_layer;
static AppTimer *timer;
static float counter = 0;
static int counts = 0;
static char text_buffer[25];
static int hands = 1;
static ActionBarLayer *action_bar;
static int y = 0;
static ClickConfigProvider pow;
static GBitmap *menuIcons;
static GBitmap *menuIcon;




const VibePattern custom_pattern = {
  .durations = (uint32_t []) {200},
  .num_segments = 1
};

static void timer_callback(void *data) {
vibes_enqueue_custom_pattern(custom_pattern);
  
}



void accel_data_handler(AccelData *data, uint32_t num_samples) {
if(hands == 1){  
if(data->y < -500 && data->y != 0){
if(counts == 1){
 timer = app_timer_register(225 /* milliseconds */, timer_callback, NULL);
  // A timer can be canceled with `app_timer_cancel()`
}else
if(counts == 2){
 timer = app_timer_register(450 /* milliseconds */, timer_callback, NULL);
  // A timer can be canceled with `app_timer_cancel()`
}else
if(counts == 3){
 timer = app_timer_register(675 /* milliseconds */, timer_callback, NULL);
  // A timer can be canceled with `app_timer_cancel()`
}else
if(counts == 4){
 timer = app_timer_register(900 /* milliseconds */, timer_callback, NULL);
  // A timer can be canceled with `app_timer_cancel()`
}else
if(counts == 6){
 timer = app_timer_register(1400 /* milliseconds */, timer_callback, NULL);
  // A timer can be canceled with `app_timer_cancel()`
}else
		if(counts == 8){
timer = app_timer_register(2000 /* milliseconds */, timer_callback, NULL);

  // A timer can be canceled with `app_timer_cancel()`
}else
if(counts == 10){
timer = app_timer_register(2600 /* milliseconds */, timer_callback, NULL);

  // A timer can be canceled with `app_timer_cancel()`
}else
if(counts == 12){
 timer = app_timer_register(3300 /* milliseconds */, timer_callback, NULL);
  // A timer can be canceled with `app_timer_cancel()`

}
}else
if(data->y > -500){
app_timer_cancel(timer);
}

}else 
if(hands == 2){
if(data->y > 500 && data->y != 0){
if(counts == 1){
 timer = app_timer_register(225 /* milliseconds */, timer_callback, NULL);
  // A timer can be canceled with `app_timer_cancel()`
}else
if(counts == 2){
 timer = app_timer_register(450 /* milliseconds */, timer_callback, NULL);
  // A timer can be canceled with `app_timer_cancel()`
}else
if(counts == 3){
 timer = app_timer_register(675 /* milliseconds */, timer_callback, NULL);
  // A timer can be canceled with `app_timer_cancel()`
}else
if(counts == 4){
 timer = app_timer_register(900 /* milliseconds */, timer_callback, NULL);
  // A timer can be canceled with `app_timer_cancel()`
}else
if(counts == 6){
 timer = app_timer_register(1400 /* milliseconds */, timer_callback, NULL);
  // A timer can be canceled with `app_timer_cancel()`
}else
		if(counts == 8){
timer = app_timer_register(2000 /* milliseconds */, timer_callback, NULL);

  // A timer can be canceled with `app_timer_cancel()`
}else
if(counts == 10){
timer = app_timer_register(2600 /* milliseconds */, timer_callback, NULL);

  // A timer can be canceled with `app_timer_cancel()`
}else
if(counts == 12){
 timer = app_timer_register(3300 /* milliseconds */, timer_callback, NULL);
  // A timer can be canceled with `app_timer_cancel()`

}
}else
if(data->y < 500){
app_timer_cancel(timer);
}
}
}


static void select_click_handler(ClickRecognizerRef recognizer, void *context) {

accel_data_service_subscribe(2, &accel_data_handler);
 text_layer_set_text(text_layer, "Start Pouring :)");
	
}



static void up_click_handler(ClickRecognizerRef recognizer, void *context) { 

	counts += 1;
	if(counts == 1){
	snprintf(text_buffer, 20, "%s", ".25oz");
}else
	if(counts == 2){
	snprintf(text_buffer, 20, "%s", ".5oz");
}else
		if(counts == 3){
	snprintf(text_buffer, 20, "%s", ".75oz");
}else
			if(counts == 4){
	snprintf(text_buffer, 20, "%s", "1oz");
}else
	if(counts == 5){
	snprintf(text_buffer, 20, "%s", "1.25oz");
}else
		if(counts == 6){
	snprintf(text_buffer, 20, "%s", "1.5oz");
}else
			if(counts == 7){
	snprintf(text_buffer, 20, "%s", "1.75oz");
}else
	if(counts == 8){
	snprintf(text_buffer, 20, "%s", "2oz");
}else
		if(counts == 9){
	snprintf(text_buffer, 20, "%s", "2.25oz");
}else
			if(counts == 10){
	snprintf(text_buffer, 20, "%s", "2.5oz");
}else
	if(counts == 11){
	snprintf(text_buffer, 20, "%s", "2.75oz");
}else
		if(counts == 12){
	snprintf(text_buffer, 20, "%s", "3oz");
}else
	if(counts == 13){
counts = 12;
}else

if(counts == 0){
counts = 1;
}
	

	
  text_layer_set_text(text_layer, text_buffer);
}

static void down_click_handler(ClickRecognizerRef recognizer, void *context) {

	
	
  counts -= 1;
	if(counts == 1){
	snprintf(text_buffer, 20, "%s", ".25oz");
}else
	if(counts == 2){
	snprintf(text_buffer, 20, "%s", ".5oz");
}else
		if(counts == 3){
	snprintf(text_buffer, 20, "%s", ".75oz");
}else
			if(counts == 4){
	snprintf(text_buffer, 20, "%s", "1oz");
}else
	if(counts == 5){
	snprintf(text_buffer, 20, "%s", "1.25oz");
}else
		if(counts == 6){
	snprintf(text_buffer, 20, "%s", "1.5oz");
}else
			if(counts == 7){
	snprintf(text_buffer, 20, "%s", "1.75oz");
}else
	if(counts == 8){
	snprintf(text_buffer, 20, "%s", "2oz");
}else
		if(counts == 9){
	snprintf(text_buffer, 20, "%s", "2.25oz");
}else
			if(counts == 10){
	snprintf(text_buffer, 20, "%s", "2.5oz");
}else
	if(counts == 11){
	snprintf(text_buffer, 20, "%s", "2.75oz");
}else
		if(counts == 12){
	snprintf(text_buffer, 20, "%s", "3oz");
}else
	if(counts == 13){
counts = 12;
}else

if(counts == 0){
counts = 1;
}

text_layer_set_text(text_layer, text_buffer);

}

static void reset_clicks(){
pow = window_get_click_config_provider(window);	
}


static void ups_click_handler(ClickRecognizerRef recognizer, void *context) {

		

action_bar_layer_remove_from_window(action_bar);

text_layer_set_text(text_layer, "Vegas Bartending.");
hands = 2;
   window_set_click_config_provider(window, pow);

}

static void downs_click_handler(ClickRecognizerRef recognizer, void *context) {


action_bar_layer_remove_from_window(action_bar);

text_layer_set_text(text_layer, "Vegas Bartending.");
hands = 1;
   window_set_click_config_provider(window, pow);

}



static void click_config_providerz(void *context) {
 

}


static void click_config_providers(void *context) {

window_single_click_subscribe(BUTTON_ID_UP, (ClickHandler)  ups_click_handler);
window_single_click_subscribe(BUTTON_ID_DOWN, (ClickHandler)  downs_click_handler);

}


void select_long_click_handler(ClickRecognizerRef recognizer, void *context) {

menuIcons = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_LEFT_ICON);
menuIcon = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_RIGHT_ICON);
 action_bar = action_bar_layer_create();
  // Associate the action bar with the window:
  action_bar_layer_add_to_window(action_bar, window);
action_bar_layer_set_icon(action_bar, BUTTON_ID_UP, menuIcon);
action_bar_layer_set_icon(action_bar, BUTTON_ID_DOWN, menuIcons);
  action_bar_layer_set_click_config_provider(action_bar,
                                             click_config_providers);


}

void select_long_click_release_handler(ClickRecognizerRef recognizer, void *context) {
 
}





static void click_config_provider(void *context) {
  window_single_click_subscribe(BUTTON_ID_SELECT, select_click_handler);
  window_single_click_subscribe(BUTTON_ID_UP, up_click_handler);
  window_single_click_subscribe(BUTTON_ID_DOWN, down_click_handler);
 // long click config:
  window_long_click_subscribe(BUTTON_ID_SELECT, 700, select_long_click_handler, select_long_click_release_handler);

}


void handle_main_appear(Window *window)
{
    // We need to add the action_bar when the main-window appears. If we do this in handle_init it picks up wrong window-bounds and the size doesn't fit.
    action_bar_layer_add_to_window(action_bar, window);
}

void handle_main_disappear(Window *window)
{
    // Since we add the layer on each appear, we remove it on each disappear.
    action_bar_layer_remove_from_window(action_bar);
}	





static void window_load(Window *window) {

  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);

  text_layer = text_layer_create((GRect) { .origin = { 0, 72 }, .size = { bounds.size.w, 20 } });
  text_layer_set_text(text_layer, "Vegas Bartending.");
  text_layer_set_text_alignment(text_layer, GTextAlignmentCenter);
  layer_add_child(window_layer, text_layer_get_layer(text_layer));
   

}

static void window_unload(Window *window) {
  text_layer_destroy(text_layer);
 gbitmap_destroy(menuIcons);
	
}

static void init(void) {

  window = window_create();
  window_set_click_config_provider(window, click_config_provider);
  window_set_window_handlers(window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });

reset_clicks();
  const bool animated = true;
  window_stack_push(window, animated);

  

}

static void deinit(void) {
  window_destroy(window);
accel_data_service_unsubscribe();




}

int main(void) {
  init();

  APP_LOG(APP_LOG_LEVEL_DEBUG, "MUAHAHAHAHAHAHA YOU DID IT NOW LOOK BITCH: %p", window);




  app_event_loop();
  deinit();

}
