function solucion()
    clear, clc
    
    % LECTURA DE ECUACIONES
    
    n = input('Ingrese el numero de ecuaciones del sistema: ');
    F = sym([n]);
    disp('Ahora ingrese las ecuaciones en la forma F(X) = 0 (Ingrese F(X))');
    for i = 1:n
        F(i) = sym(input('Ecuación: ', 's'));
    end
    
    %F = [sym('x*x + y*y - 10'), sym('x*x - y*y - 1')];
    %n = length(F);
    
    % RECOLECCION DE VARIABLES
    variables = [];
    for i = 1:n
        variables = union(variables, symvar(F(i)));
    end
    
    % HALLAMOS EL JACOBIANO DE NUESTRO SISTEMA DE ECUACIONES
    jacobiano = sym([n n]);
    for i = 1:n
        temporal = gradient(F(i));
        for j = 1:n
            jacobiano(i,j) = temporal(j);
        end
    end
    
    %    LECTURA DE VALORES INICIALES
    disp('Ingrese los valores iniciales: ');
    X = [];
    for i = 1:n
        X(i) = input([char(variables(i)), ' : ']);
    end
    
    %X = [1 1];
    
    X = X';% Ya que X es un vector fila lo trasponemos para poder
           % obtener un vector columna para poder operar
    
    % ITERACIONES
    
    iteraciones = input('Ingrese el numero de iteraciones que desea: ');
    %iteraciones = 5;
    
    clc
    disp('Sistema de ecuaciones:');
    fprintf('\n');
    for i = 1:n
        fprintf('\t%s = 0\n',char(F(i)));
    end
    
    fprintf('\nValores iniciales para las variables\n\n');
    for i = 1:n
        fprintf('\t\t%s = %6f\n', char(variables(i)), X(i));
    end
    
    fprintf('\n\n');
    
    fprintf('%5s','n');
    for i = 1:n
        fprintf('%10s', [char(variables(i)),'[n]']);
    end
    fprintf('\n');
    fprintf('%5d', 0);
    for i = 1:n
        fprintf('%10.5f ', X(i));
    end
    fprintf('\n');
    
    %    CALCULO DE ITERACIONES
    
    for iteracion = 1:iteraciones
        % Evaluamos en el jacobiano
        for i = 1:n
            for j = 1:n
                evaljac(i, j) = subs(jacobiano(i,j), variables, X);
            end
        end
        
        % Evaluamos X en nuestras ecuaciones
        Fx = [];
        for i = 1:n
            Fx(i) = subs(F(i), variables, X);
        end
        Fx = Fx'; % Ya que Fx es un vector fila lo trasponemos para poder
                  % obtener un vector columna, para poder operar
                  
        % Imprimimos el resultado de la iteración
        
        X = (X - inv(evaljac) * Fx);% <-------- NEWTON!!!
        
        fprintf('%5d', iteracion);
        for i = 1:n
            fprintf('%10.5f ', X(i));
        end
        fprintf('\n');
    end
end
