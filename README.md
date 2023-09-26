# Use Figlet in C++

### Dependencies

-   **figlet** package

### example

```cpp
#include "./figlet.h"

int main() {
    ahm::figlet fig;

    fig.set_query("Hi").norm_print();
    fig
        .set_font_path("~/.local/share/fonts/ansi_regular.flf")
        .lolcat_print();
    fig
        .set_font_path("~/.local/share/fonts/ansi_regular.flf")
        .set_flags({"-t", "-c"})
        .set_query("Hi, Ahmad")
        .lolcat_print();

    fig.reset(); // reset the query, flags and font path

    // fig.norm_print(); // CE: Can't print without query
    fig.set_query("Hi").norm_print();

    fig
        .set_font_path("~/.local/share/fonts/future.flf")
        .set_query("Hello, world!")
        .norm_print();

    fig.lolcat_print();

    return 0;
}
```

![example](example.png)
