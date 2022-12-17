import gzip
import subprocess
Import("env")

subprocess.check_call("npm run build", cwd="./web", shell=True)
with open("src/page.h", "w") as h:
    with open("web/dist/index.html", "rb") as html:
        h.write("""/*** GENERATED FILE ***/\n""")
        h.write("""const uint8_t MAIN_page[] PROGMEM = {\n""")
        bytes = gzip.compress(html.read())
        h.write(",".join(map(hex, list(bytes))))
        h.write("""\n};\n""")
