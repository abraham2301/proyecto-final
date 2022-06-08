CREATE TABLE `clientes` (
  `id_Cliente` int NOT NULL AUTO_INCREMENT,
  `Nombres` varchar(60) DEFAULT NULL,
  `Apellidos` varchar(60) DEFAULT NULL,
  `NIT` varchar(12) DEFAULT NULL,
  `telefono` varchar(25) DEFAULT NULL,
  `Correo_Electronico` varchar(45) DEFAULT NULL,
  `Fecha_Ingreso` datetime DEFAULT NULL,
  `genero` bit(1) DEFAULT NULL,
  PRIMARY KEY (`id_Cliente`)
) ENGINE=InnoDB AUTO_INCREMENT=14 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

CREATE TABLE `compras` (
  `id_compras` int NOT NULL AUTO_INCREMENT,
  `no_orden_compra` int DEFAULT NULL,
  `idproveedor` int DEFAULT NULL,
  `fecha_orden` date DEFAULT NULL,
  `fechaingreso` datetime DEFAULT NULL,
  PRIMARY KEY (`id_compras`),
  KEY `idproveedores_idproveedores_idx` (`idproveedor`),
  CONSTRAINT `idproveedor_idproveedor` FOREIGN KEY (`idproveedor`) REFERENCES `proveedores` (`id_Proveedores`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

CREATE TABLE `compras_detalle` (
  `idcompras_detalle` bigint NOT NULL AUTO_INCREMENT,
  `idcompra` int DEFAULT NULL,
  `idProducto` int DEFAULT NULL,
  `cantidad` int DEFAULT NULL,
  `precio_costo_unitario` decimal(8,2) DEFAULT NULL,
  PRIMARY KEY (`idcompras_detalle`),
  KEY `idproducto_idproducto_idx` (`idProducto`),
  KEY `idcompra_idcompra_idx` (`idcompra`),
  CONSTRAINT `idcompra_idcompra` FOREIGN KEY (`idcompra`) REFERENCES `compras` (`id_compras`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `idproducto_idproductoss` FOREIGN KEY (`idProducto`) REFERENCES `productos` (`id_Producto`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

CREATE TABLE `empleados` (
  `id_Empleados` int NOT NULL AUTO_INCREMENT,
  `Nombres` varchar(60) DEFAULT NULL,
  `Apellidos` varchar(60) DEFAULT NULL,
  `Direccion` varchar(80) DEFAULT NULL,
  `Telefono` varchar(25) DEFAULT NULL,
  `DPI` varchar(18) DEFAULT NULL,
  `Fecha_Nacimiento` date DEFAULT NULL,
  `id_Puesto` smallint DEFAULT NULL,
  `Fecha_Inicio_Labores` date DEFAULT NULL,
  `Fecha_Ingreso` datetime DEFAULT NULL,
  `Genero` bit(1) DEFAULT NULL,
  PRIMARY KEY (`id_Empleados`),
  KEY `idpuesto_idpuesto_idx` (`id_Puesto`),
  CONSTRAINT `idpuesto_idpuesto` FOREIGN KEY (`id_Puesto`) REFERENCES `puestos` (`id_Puesto`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

CREATE TABLE `marcas` (
  `id_Marcas` smallint NOT NULL AUTO_INCREMENT,
  `Marca` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`id_Marcas`)
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

CREATE TABLE `productos` (
  `id_Producto` int NOT NULL AUTO_INCREMENT,
  `Producto` varchar(50) DEFAULT NULL,
  `id_Marca` smallint DEFAULT NULL,
  `Descripcion` varchar(100) DEFAULT NULL,
  `Imagen` varchar(30) DEFAULT NULL,
  `Precio_Costo` decimal(8,2) DEFAULT NULL,
  `Precio_Venta` decimal(8,2) DEFAULT NULL,
  `Existencia` int DEFAULT NULL,
  `Fecha_Ingreso` datetime DEFAULT NULL,
  PRIMARY KEY (`id_Producto`),
  KEY `idmarca_idmarca_idx` (`id_Marca`),
  CONSTRAINT `idmarca_idmarca` FOREIGN KEY (`id_Marca`) REFERENCES `marcas` (`id_Marcas`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=32 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

CREATE TABLE `proveedores` (
  `id_Proveedores` int NOT NULL AUTO_INCREMENT,
  `proveedor` varchar(60) DEFAULT NULL,
  `nit` varchar(12) DEFAULT NULL,
  `direccion` varchar(80) DEFAULT NULL,
  `telefono` varchar(25) DEFAULT NULL,
  PRIMARY KEY (`id_Proveedores`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

CREATE TABLE `puestos` (
  `id_Puesto` smallint NOT NULL AUTO_INCREMENT,
  `Puesto` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`id_Puesto`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

CREATE TABLE `ventas` (
  `id_ventas` int NOT NULL AUTO_INCREMENT,
  `No_Factura` int DEFAULT NULL,
  `Serie` char(1) DEFAULT NULL,
  `Fecha_facturada` date DEFAULT NULL,
  `id_Cliente` int DEFAULT NULL,
  `id_Empleado` int DEFAULT NULL,
  `fecha_Ingreso` datetime DEFAULT NULL,
  PRIMARY KEY (`id_ventas`),
  KEY `idempleado_idempleado_idx` (`id_Empleado`),
  KEY `idcliente_idcliente_idx` (`id_Cliente`),
  CONSTRAINT `idcliente_idcliente` FOREIGN KEY (`id_Cliente`) REFERENCES `clientes` (`id_Cliente`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `idempleado_idempleado` FOREIGN KEY (`id_Empleado`) REFERENCES `empleados` (`id_Empleados`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=18 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

CREATE TABLE `ventas_detalle` (
  `id_Venta_Detalle` bigint NOT NULL AUTO_INCREMENT,
  `id_Venta` int DEFAULT NULL,
  `id_Producto` int DEFAULT NULL,
  `Cantidad` varchar(45) DEFAULT NULL,
  `Precio_Unitario` decimal(8,2) DEFAULT NULL,
  PRIMARY KEY (`id_Venta_Detalle`),
  KEY `idventadetalle_idventadetalle_idx` (`id_Venta`),
  KEY `idproducto_idproducto_idx` (`id_Producto`),
  CONSTRAINT `idproducto_idproducto` FOREIGN KEY (`id_Producto`) REFERENCES `productos` (`id_Producto`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `idventadetalle_idventadetalle` FOREIGN KEY (`id_Venta`) REFERENCES `ventas` (`id_ventas`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

