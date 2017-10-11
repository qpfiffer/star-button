// vim: noet ts=4 sw=4
#include <gtk/gtk.h>

#define WIDTH 550
#define HEIGHT 460


static gboolean configure_event(GtkWidget *widget, GtkEvent *event, gpointer user_data) {
	return FALSE;
}

static gboolean draw(GtkWidget *widget, cairo_t *cr, gpointer user_data) {
	cairo_set_operator(cr, CAIRO_OPERATOR_CLEAR);
	cairo_rectangle(cr, 0, 0, WIDTH, HEIGHT);
	cairo_fill(cr);

	cairo_set_operator(cr, CAIRO_OPERATOR_OVER);
	cairo_set_source_rgba(cr, 0.5f, 1.0f, 0.0f, 1.0f);

	cairo_surface_t *image = cairo_image_surface_create_from_png("./star.png");
	cairo_set_source_surface(cr, image, 0, 0);
	cairo_paint(cr);

	return FALSE;
}

static void activate(GtkApplication *app, gpointer user_data) {
	GtkWidget *window = gtk_application_window_new(app);

	gtk_window_set_default_size(GTK_WINDOW(window), WIDTH, HEIGHT);
	gtk_window_set_decorated(GTK_WINDOW(window), 0);
	gtk_widget_show_all(window);

	gtk_widget_set_app_paintable(window, 1);

	GdkScreen *screen = gtk_widget_get_screen(window);
	GdkVisual *visual = gdk_screen_get_rgba_visual(screen);
	gtk_widget_set_visual(window, visual);

	GtkWidget *draw_area = gtk_drawing_area_new();
	gtk_container_add(GTK_CONTAINER(window), draw_area);
	g_signal_connect(G_OBJECT(draw_area), "draw", G_CALLBACK(draw), NULL);
	g_signal_connect(G_OBJECT(draw_area), "configure_event", G_CALLBACK(configure_event), NULL);
}

int main(int argc, char *argv[]) {
	GtkApplication *app = NULL;
	int status = 0;

	app = gtk_application_new("org.quinlan.star_button", G_APPLICATION_FLAGS_NONE);
	if (!app) {
		printf("Could not start new app.\n");
		return -1;
	}
	g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
	status = g_application_run(G_APPLICATION(app), argc, argv);
	g_object_unref (app);

	return status;
}
