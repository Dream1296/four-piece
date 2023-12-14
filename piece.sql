-- MySQL dump 10.13  Distrib 8.0.35, for Linux (aarch64)
--
-- Host: localhost    Database: piece
-- ------------------------------------------------------
-- Server version	8.0.35-0ubuntu0.22.04.1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `piece0`
--

DROP TABLE IF EXISTS `piece0`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `piece0` (
  `id` int NOT NULL AUTO_INCREMENT,
  `x1` int NOT NULL COMMENT '旧的x坐标',
  `y1` int NOT NULL COMMENT '旧的y坐标',
  `x2` int NOT NULL COMMENT '新的x轴',
  `y2` int NOT NULL COMMENT '新的y轴',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=120 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `piece0`
--

LOCK TABLES `piece0` WRITE;
/*!40000 ALTER TABLE `piece0` DISABLE KEYS */;
INSERT INTO `piece0` VALUES (9,2,0,2,1),(10,3,0,3,1),(11,1,0,1,1),(12,3,1,2,1),(13,1,1,1,2),(14,2,1,2,2),(15,1,0,1,1),(16,2,0,2,1),(17,3,0,3,1),(18,3,1,3,0),(19,3,0,3,1),(20,0,0,0,1),(21,2,0,2,1),(22,1,0,1,1),(23,1,0,1,1),(24,1,0,1,1),(25,2,0,2,1),(26,1,0,1,1),(27,2,0,2,1),(28,2,1,3,1),(29,2,0,2,1),(30,2,0,2,1),(31,1,0,1,1),(32,2,0,2,1),(33,1,0,1,1),(34,1,1,2,1),(35,0,0,0,1),(36,3,0,3,1),(37,3,1,2,1),(38,0,1,1,1),(39,2,0,2,1),(40,1,0,1,1),(41,1,1,1,0),(42,1,0,1,1),(43,0,0,0,1),(44,1,0,1,1),(45,3,0,3,1),(46,2,0,1,0),(47,1,0,2,0),(48,1,1,0,1),(49,0,1,1,1),(50,1,1,1,0),(51,1,0,1,1),(52,1,1,2,1),(53,2,1,1,1),(54,1,1,2,1),(55,2,0,2,1),(56,1,0,1,1),(57,3,0,3,1),(58,2,1,2,0),(59,1,0,1,1),(60,2,0,2,1),(61,2,1,3,1),(62,3,1,2,1),(63,2,1,3,1),(64,1,0,1,1),(65,3,0,3,1),(66,3,1,2,1),(67,0,0,1,0),(68,2,0,3,0),(69,3,0,2,0),(70,1,1,0,1),(71,2,1,3,1),(72,2,0,2,1),(73,2,1,2,0),(74,3,1,2,1),(75,2,1,1,1),(76,1,1,2,1),(77,1,0,2,0),(78,3,0,3,1),(79,0,0,0,1),(80,0,1,0,2),(81,0,2,1,2),(82,1,2,2,2),(83,2,0,2,1),(84,2,0,2,1),(85,2,0,2,1),(86,2,0,2,1),(87,2,0,2,1),(88,1,0,1,1),(89,0,0,1,0),(90,1,0,2,0),(91,2,0,2,1),(92,2,1,2,2),(93,3,0,3,1),(94,3,1,3,2),(95,1,0,1,1),(96,2,0,2,1),(97,0,0,0,1),(98,0,1,0,2),(99,2,0,2,1),(100,1,0,1,1),(101,3,0,2,0),(102,0,0,0,1),(103,2,0,2,1),(104,1,0,1,1),(105,2,0,2,1),(106,0,0,0,1),(107,3,0,3,1),(108,2,1,2,2),(109,3,1,2,1),(110,3,1,2,1),(111,1,0,1,1),(112,1,0,1,1),(113,2,0,2,1),(114,3,0,2,0),(115,2,1,1,1),(116,2,0,1,0),(117,1,1,2,1),(118,1,0,2,0),(119,2,0,2,1);
/*!40000 ALTER TABLE `piece0` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `piece1`
--

DROP TABLE IF EXISTS `piece1`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `piece1` (
  `id` int NOT NULL AUTO_INCREMENT,
  `x1` int NOT NULL,
  `y1` int NOT NULL,
  `x2` int NOT NULL,
  `y2` int NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=168 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `piece1`
--

LOCK TABLES `piece1` WRITE;
/*!40000 ALTER TABLE `piece1` DISABLE KEYS */;
INSERT INTO `piece1` VALUES (9,2,3,2,2),(10,1,3,1,2),(11,2,3,2,2),(12,1,3,1,2),(13,1,2,2,2),(14,1,3,1,2),(15,1,3,1,2),(16,1,2,2,2),(17,2,2,1,2),(18,1,2,2,2),(19,2,2,1,2),(20,0,3,0,2),(21,0,2,0,1),(22,0,1,1,1),(23,1,1,2,1),(24,2,3,2,2),(25,2,2,1,2),(26,3,3,3,2),(27,3,2,2,2),(28,1,2,1,1),(29,1,3,2,3),(30,2,2,1,2),(31,1,1,0,1),(32,2,3,2,2),(33,2,2,1,2),(34,3,3,3,2),(35,2,3,2,2),(36,2,3,2,2),(37,2,2,1,2),(38,1,3,1,2),(39,1,2,2,2),(40,2,3,2,2),(41,2,2,1,2),(42,1,2,1,1),(43,1,3,1,2),(44,1,2,2,2),(45,2,2,2,1),(46,3,3,3,2),(47,2,3,2,2),(48,1,3,2,3),(49,3,3,3,2),(50,1,3,1,2),(51,1,2,2,2),(52,2,2,1,2),(53,1,2,2,2),(54,2,2,1,2),(55,3,3,3,2),(56,3,2,2,2),(57,1,2,1,1),(58,2,2,3,2),(59,3,2,2,2),(60,2,2,1,2),(61,1,2,0,2),(62,1,1,1,2),(63,1,3,1,2),(64,1,2,2,2),(65,2,2,1,2),(66,1,2,2,2),(67,2,3,2,2),(68,2,3,2,2),(69,1,3,1,2),(70,2,3,2,2),(71,2,2,1,2),(72,0,3,0,2),(73,0,2,0,1),(74,0,1,1,1),(75,1,1,2,1),(76,3,3,3,2),(77,3,2,2,2),(78,2,3,2,2),(79,2,2,1,2),(80,1,3,2,3),(81,2,3,2,2),(82,2,2,2,1),(83,1,2,2,2),(84,2,2,1,2),(85,2,1,2,2),(86,1,2,0,2),(87,2,2,1,2),(88,3,3,3,2),(89,2,3,2,2),(90,1,3,2,3),(91,2,2,1,2),(92,3,3,3,2),(93,1,2,1,1),(94,2,3,2,2),(95,2,2,1,2),(96,1,2,2,2),(97,2,2,1,2),(98,3,3,3,2),(99,2,3,2,2),(100,2,3,2,2),(101,2,3,2,2),(102,2,2,1,2),(103,1,2,2,2),(104,2,2,1,2),(105,3,3,2,3),(106,2,3,2,2),(107,2,2,2,3),(108,1,2,1,1),(109,0,3,0,2),(110,2,3,2,2),(111,1,1,1,2),(112,1,2,1,3),(113,1,3,1,2),(114,1,2,1,3),(115,0,2,1,2),(116,2,3,2,2),(117,1,3,1,2),(118,2,2,2,1),(119,1,2,1,1),(120,0,3,1,3),(121,1,3,1,2),(122,2,3,2,2),(123,1,3,2,3),(124,2,3,2,2),(125,1,3,2,3),(126,2,3,2,2),(127,2,3,2,2),(128,1,3,2,3),(129,2,3,2,2),(130,1,3,2,3),(131,2,2,1,2),(132,2,3,2,2),(133,2,2,1,2),(134,0,3,0,2),(135,0,2,0,1),(136,0,1,0,0),(137,2,3,2,2),(138,2,2,1,2),(139,1,2,2,2),(140,3,3,2,3),(141,1,3,1,2),(142,2,3,2,2),(143,1,3,2,3),(144,2,2,1,2),(145,2,3,1,3),(146,1,2,0,2),(147,2,3,2,2),(148,2,2,1,2),(149,1,2,2,2),(150,2,2,1,2),(151,1,2,0,2),(152,1,3,1,2),(153,1,2,2,2),(154,1,3,1,2),(155,2,3,2,2),(156,2,2,1,2),(157,1,2,2,2),(158,1,3,1,2),(159,3,3,3,2),(160,3,2,2,2),(161,0,3,0,2),(162,2,3,2,2),(163,1,3,1,2),(164,2,3,2,2),(165,0,3,0,2),(166,1,3,1,2),(167,2,3,2,2);
/*!40000 ALTER TABLE `piece1` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `player`
--

DROP TABLE IF EXISTS `player`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `player` (
  `id` int NOT NULL,
  `players` char(1) NOT NULL COMMENT '表示玩家代码',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `player`
--

LOCK TABLES `player` WRITE;
/*!40000 ALTER TABLE `player` DISABLE KEYS */;
INSERT INTO `player` VALUES (1,'0');
/*!40000 ALTER TABLE `player` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2023-12-14 22:13:45
