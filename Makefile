.PHONY: clean All

All:
	@echo "----------Building project:[ ImageLoader - Debug ]----------"
	@cd "ImageLoader" && "$(MAKE)" -f  "ImageLoader.mk"
clean:
	@echo "----------Cleaning project:[ ImageLoader - Debug ]----------"
	@cd "ImageLoader" && "$(MAKE)" -f  "ImageLoader.mk" clean
