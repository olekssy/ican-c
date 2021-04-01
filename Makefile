help:           ## Show this help.
	@fgrep -h "##" $(MAKEFILE_LIST) | fgrep -v fgrep | sed -e 's/\\$$//' | sed -e 's/##//'	

clean:		## Delete all compiled binary files.
	@find . -type f -name "*.o" -delete
	@echo "Deleted all *.o binary files."

