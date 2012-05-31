#include <stdio.h>
#include <string.h>

#include "contact.h"
#include "project_tools.h"

int main(int argc, char* argv[])
{
	struct contact *yan;

	yan = create_contact();
	display_contact(yan);
	edit_contact(yan);
	display_contact(yan);

	return 0;
}
