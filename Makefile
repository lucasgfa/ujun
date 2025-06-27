# Compilador e flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g

# Diretórios
SRCDIR = .
INCDIR = .
OBJDIR = obj
BINDIR = bin

# Busca todos os .cpp na pasta atual
SOURCES = $(wildcard $(SRCDIR)/*.cpp)

# Arquivos objeto na pasta obj
OBJECTS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))

# Executável final
EXECUTABLE = $(BINDIR)/agencia_viagem.exe

# Flags para pré-processador para incluir cabeçalhos na pasta atual
CPPFLAGS = -I$(INCDIR)

# Alvo padrão
all: $(EXECUTABLE)

# Linka objetos para gerar executável
$(EXECUTABLE): $(OBJECTS)
	@if not exist $(BINDIR) mkdir $(BINDIR)
	@echo ">>> Linkando para criar o executável..."
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@
	@echo ">>> Executável '$(EXECUTABLE)' construído com sucesso!"

# Compila cada .cpp para .o em obj
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@if not exist $(OBJDIR) mkdir $(OBJDIR)
	@echo ">>> Compilando '$<'"
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

# Limpar build
clean:
	@echo ">>> Limpando arquivos de build..."
	if exist $(OBJDIR) rmdir /s /q $(OBJDIR)
	if exist $(BINDIR) rmdir /s /q $(BINDIR)
	@echo ">>> Limpeza concluída."

.PHONY: all clean
