TARGET_DIR=/home/hubert/public_html/coding
THEME_NAME=default
all:
	cp -rf mythemes slides.md $(TARGET_DIR)
	(cd $(TARGET_DIR) && rm -rf theme && landslide slides.md -d coding.html -c -r -t mythemes/$(THEME_NAME))
clean:
	find . -name '*~' -exec rm -f {} +
	(cd $(TARGET_DIR) && rm -rf theme mythemes slides.md coding.html)
