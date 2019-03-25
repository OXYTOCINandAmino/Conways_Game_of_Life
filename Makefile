.PHONY: clean All

All:
	@echo "----------Building project:[ Conway - Debug ]----------"
	@cd "Conway" && "$(MAKE)" -f  "Conway.mk"
clean:
	@echo "----------Cleaning project:[ Conway - Debug ]----------"
	@cd "Conway" && "$(MAKE)" -f  "Conway.mk" clean
